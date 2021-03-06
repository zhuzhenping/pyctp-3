#include "TdSpi.h"

#include "Windows.h"

///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void TdSpi::OnFrontConnected(){
    OutputDebugString("OnFrontConnected");
    OnStaticFrontConnected();
}

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
void TdSpi::OnFrontDisconnected(int nReason){
    OutputDebugString("OnFrontDisconnected");
    OnStaticFrontDisconnected(nReason);
}
	
///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void TdSpi::OnHeartBeatWarning(int nTimeLapse){
    OutputDebugString("OnHeartBeatWarning");
    OnStaticHeartBeatWarning(nTimeLapse);
}

///客户端认证响应
void TdSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspAuthenticate");
    OnStaticRspAuthenticate(pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
}


///登录请求响应
void TdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspUserLogin");
    OnStaticRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

///登出请求响应
void TdSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspUserLogout");
    OnStaticRspUserLogout(pUserLogout, pRspInfo, nRequestID, bIsLast);
}

///用户口令更新请求响应
void TdSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspUserPasswordUpdate");
    OnStaticRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
}

///资金账户口令更新请求响应
void TdSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspTradingAccountPasswordUpdate");
    OnStaticRspTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
}

///报单录入请求响应
void TdSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspOrderInsert");
    OnStaticRspOrderInsert(pInputOrder, pRspInfo, nRequestID, bIsLast);
}

///预埋单录入请求响应
void TdSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspParkedOrderInsert");
    OnStaticRspParkedOrderInsert(pParkedOrder, pRspInfo, nRequestID, bIsLast);
}

///预埋撤单录入请求响应
void TdSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspParkedOrderAction");
    OnStaticRspParkedOrderAction(pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

///报单操作请求响应
void TdSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspOrderAction");
    OnStaticRspOrderAction(pInputOrderAction, pRspInfo, nRequestID, bIsLast);
}

///查询最大报单数量响应
void TdSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQueryMaxOrderVolume");
    OnStaticRspQueryMaxOrderVolume(pQueryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
}

///投资者结算结果确认响应
void TdSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspSettlementInfoConfirm");
    OnStaticRspSettlementInfoConfirm(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
}

///删除预埋单响应
void TdSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspRemoveParkedOrder");
    OnStaticRspRemoveParkedOrder(pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
}

///删除预埋撤单响应
void TdSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspRemoveParkedOrderAction");
    OnStaticRspRemoveParkedOrderAction(pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

///执行宣告录入请求响应
void TdSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspExecOrderInsert");
    OnStaticRspExecOrderInsert(pInputExecOrder, pRspInfo, nRequestID, bIsLast);
}

///执行宣告操作请求响应
void TdSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspExecOrderAction");
    OnStaticRspExecOrderAction(pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
}

///询价录入请求响应
void TdSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspForQuoteInsert");
    OnStaticRspForQuoteInsert(pInputForQuote, pRspInfo, nRequestID, bIsLast);
}

///报价录入请求响应
void TdSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQuoteInsert");
    OnStaticRspQuoteInsert(pInputQuote, pRspInfo, nRequestID, bIsLast);
}

///报价操作请求响应
void TdSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQuoteAction");
    OnStaticRspQuoteAction(pInputQuoteAction, pRspInfo, nRequestID, bIsLast);
}

///申请组合录入请求响应
void TdSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspCombActionInsert");
    OnStaticRspCombActionInsert(pInputCombAction, pRspInfo, nRequestID, bIsLast);
}

///请求查询报单响应
void TdSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryOrder");
    OnStaticRspQryOrder(pOrder, pRspInfo, nRequestID, bIsLast);
}

///请求查询成交响应
void TdSpi::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryTrade");
    OnStaticRspQryTrade(pTrade, pRspInfo, nRequestID, bIsLast);
}

///请求查询投资者持仓响应
void TdSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryInvestorPosition");
    OnStaticRspQryInvestorPosition(pInvestorPosition, pRspInfo, nRequestID, bIsLast);
}

///请求查询资金账户响应
void TdSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryTradingAccount");
    OnStaticRspQryTradingAccount(pTradingAccount, pRspInfo, nRequestID, bIsLast);
}

///请求查询投资者响应
void TdSpi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryInvestor");
    OnStaticRspQryInvestor(pInvestor, pRspInfo, nRequestID, bIsLast);
}

///请求查询交易编码响应
void TdSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryTradingCode");
    OnStaticRspQryTradingCode(pTradingCode, pRspInfo, nRequestID, bIsLast);
}

///请求查询合约保证金率响应
void TdSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryInstrumentMarginRate");
    OnStaticRspQryInstrumentMarginRate(pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
}

///请求查询合约手续费率响应
void TdSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryInstrumentCommissionRate");
    OnStaticRspQryInstrumentCommissionRate(pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
}

///请求查询交易所响应
void TdSpi::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryExchange");
    OnStaticRspQryExchange(pExchange, pRspInfo, nRequestID, bIsLast);
}

///请求查询产品响应
void TdSpi::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryProduct");
    OnStaticRspQryProduct(pProduct, pRspInfo, nRequestID, bIsLast);
}

///请求查询合约响应
void TdSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryInstrument");
    OnStaticRspQryInstrument(pInstrument, pRspInfo, nRequestID, bIsLast);
}

///请求查询行情响应
void TdSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryDepthMarketData");
    OnStaticRspQryDepthMarketData(pDepthMarketData, pRspInfo, nRequestID, bIsLast);
}

///请求查询投资者结算结果响应
void TdSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQrySettlementInfo");
    OnStaticRspQrySettlementInfo(pSettlementInfo, pRspInfo, nRequestID, bIsLast);
}

///请求查询转帐银行响应
void TdSpi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryTransferBank");
    OnStaticRspQryTransferBank(pTransferBank, pRspInfo, nRequestID, bIsLast);
}

///请求查询投资者持仓明细响应
void TdSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryInvestorPositionDetail");
    OnStaticRspQryInvestorPositionDetail(pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
}

///请求查询客户通知响应
void TdSpi::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryNotice");
    OnStaticRspQryNotice(pNotice, pRspInfo, nRequestID, bIsLast);
}

///请求查询结算信息确认响应
void TdSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQrySettlementInfoConfirm");
    OnStaticRspQrySettlementInfoConfirm(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
}

///请求查询投资者持仓明细响应
void TdSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryInvestorPositionCombineDetail");
    OnStaticRspQryInvestorPositionCombineDetail(pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
}

///查询保证金监管系统经纪公司资金账户密钥响应
void TdSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryCFMMCTradingAccountKey");
    OnStaticRspQryCFMMCTradingAccountKey(pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
}

///请求查询仓单折抵信息响应
void TdSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryEWarrantOffset");
    OnStaticRspQryEWarrantOffset(pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
}

///请求查询投资者品种/跨品种保证金响应
void TdSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryInvestorProductGroupMargin");
    OnStaticRspQryInvestorProductGroupMargin(pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
}

///请求查询交易所保证金率响应
void TdSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryExchangeMarginRate");
    OnStaticRspQryExchangeMarginRate(pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
}

///请求查询交易所调整保证金率响应
void TdSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryExchangeMarginRateAdjust");
    OnStaticRspQryExchangeMarginRateAdjust(pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
}

///请求查询汇率响应
void TdSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryExchangeRate");
    OnStaticRspQryExchangeRate(pExchangeRate, pRspInfo, nRequestID, bIsLast);
}

///请求查询二级代理操作员银期权限响应
void TdSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQrySecAgentACIDMap");
    OnStaticRspQrySecAgentACIDMap(pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
}

///请求查询产品组
void TdSpi::OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryProductGroup");
    OnStaticRspQryProductGroup(pProductGroup, pRspInfo, nRequestID, bIsLast);
}

///请求查询报单手续费响应
void TdSpi::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryInstrumentOrderCommRate");
    OnStaticRspQryInstrumentOrderCommRate(pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast);
}

///请求查询期权交易成本响应
void TdSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryOptionInstrTradeCost");
    OnStaticRspQryOptionInstrTradeCost(pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast);
}

///请求查询期权合约手续费响应
void TdSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryOptionInstrCommRate");
    OnStaticRspQryOptionInstrCommRate(pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
}

///请求查询执行宣告响应
void TdSpi::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryExecOrder");
    OnStaticRspQryExecOrder(pExecOrder, pRspInfo, nRequestID, bIsLast);
}

///请求查询询价响应
void TdSpi::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryForQuote");
    OnStaticRspQryForQuote(pForQuote, pRspInfo, nRequestID, bIsLast);
}

///请求查询报价响应
void TdSpi::OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryQuote");
    OnStaticRspQryQuote(pQuote, pRspInfo, nRequestID, bIsLast);
}

///请求查询组合合约安全系数响应
void TdSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryCombInstrumentGuard");
    OnStaticRspQryCombInstrumentGuard(pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast);
}

///请求查询申请组合响应
void TdSpi::OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryCombAction");
    OnStaticRspQryCombAction(pCombAction, pRspInfo, nRequestID, bIsLast);
}

///请求查询转帐流水响应
void TdSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryTransferSerial");
    OnStaticRspQryTransferSerial(pTransferSerial, pRspInfo, nRequestID, bIsLast);
}

///请求查询银期签约关系响应
void TdSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryAccountregister");
    OnStaticRspQryAccountregister(pAccountregister, pRspInfo, nRequestID, bIsLast);
}

///错误应答
void TdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspError");
    OnStaticRspError(pRspInfo, nRequestID, bIsLast);
}

///报单通知
void TdSpi::OnRtnOrder(CThostFtdcOrderField *pOrder){
    OutputDebugString("OnRtnOrder");
    OnStaticRtnOrder(pOrder);
}

///成交通知
void TdSpi::OnRtnTrade(CThostFtdcTradeField *pTrade){
    OutputDebugString("OnRtnTrade");
    OnStaticRtnTrade(pTrade);
}

///报单录入错误回报
void TdSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnOrderInsert");
    OnStaticErrRtnOrderInsert(pInputOrder, pRspInfo);
}

///报单操作错误回报
void TdSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnOrderAction");
    OnStaticErrRtnOrderAction(pOrderAction, pRspInfo);
}

///合约交易状态通知
void TdSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus){
    OutputDebugString("OnRtnInstrumentStatus");
    OnStaticRtnInstrumentStatus(pInstrumentStatus);
}

///交易通知
void TdSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo){
    OutputDebugString("OnRtnTradingNotice");
    OnStaticRtnTradingNotice(pTradingNoticeInfo);
}

///提示条件单校验错误
void TdSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder){
    OutputDebugString("OnRtnErrorConditionalOrder");
    OnStaticRtnErrorConditionalOrder(pErrorConditionalOrder);
}

///执行宣告通知
void TdSpi::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder){
    OutputDebugString("OnRtnExecOrder");
    OnStaticRtnExecOrder(pExecOrder);
}

///执行宣告录入错误回报
void TdSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnExecOrderInsert");
    OnStaticErrRtnExecOrderInsert(pInputExecOrder, pRspInfo);
}

///执行宣告操作错误回报
void TdSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnExecOrderAction");
    OnStaticErrRtnExecOrderAction(pExecOrderAction, pRspInfo);
}

///询价录入错误回报
void TdSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnForQuoteInsert");
    OnStaticErrRtnForQuoteInsert(pInputForQuote, pRspInfo);
}

///报价通知
void TdSpi::OnRtnQuote(CThostFtdcQuoteField *pQuote){
    OutputDebugString("OnRtnQuote");
    OnStaticRtnQuote(pQuote);
}

///报价录入错误回报
void TdSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnQuoteInsert");
    OnStaticErrRtnQuoteInsert(pInputQuote, pRspInfo);
}

///报价操作错误回报
void TdSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnQuoteAction");
    OnStaticErrRtnQuoteAction(pQuoteAction, pRspInfo);
}

///询价通知
void TdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp){
    OutputDebugString("OnRtnForQuoteRsp");
    OnStaticRtnForQuoteRsp(pForQuoteRsp);
}

///保证金监控中心用户令牌
void TdSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken){
    OutputDebugString("OnRtnCFMMCTradingAccountToken");
    OnStaticRtnCFMMCTradingAccountToken(pCFMMCTradingAccountToken);
}

///申请组合通知
void TdSpi::OnRtnCombAction(CThostFtdcCombActionField *pCombAction){
    OutputDebugString("OnRtnCombAction");
    OnStaticRtnCombAction(pCombAction);
}

///申请组合录入错误回报
void TdSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnCombActionInsert");
    OnStaticErrRtnCombActionInsert(pInputCombAction, pRspInfo);
}

///请求查询签约银行响应
void TdSpi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryContractBank");
    OnStaticRspQryContractBank(pContractBank, pRspInfo, nRequestID, bIsLast);
}

///请求查询预埋单响应
void TdSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryParkedOrder");
    OnStaticRspQryParkedOrder(pParkedOrder, pRspInfo, nRequestID, bIsLast);
}

///请求查询预埋撤单响应
void TdSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryParkedOrderAction");
    OnStaticRspQryParkedOrderAction(pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
}

///请求查询交易通知响应
void TdSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryTradingNotice");
    OnStaticRspQryTradingNotice(pTradingNotice, pRspInfo, nRequestID, bIsLast);
}

///请求查询经纪公司交易参数响应
void TdSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryBrokerTradingParams");
    OnStaticRspQryBrokerTradingParams(pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
}

///请求查询经纪公司交易算法响应
void TdSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQryBrokerTradingAlgos");
    OnStaticRspQryBrokerTradingAlgos(pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
}

///请求查询监控中心用户令牌
void TdSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQueryCFMMCTradingAccountToken");
    OnStaticRspQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast);
}

///银行发起银行资金转期货通知
void TdSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer){
    OutputDebugString("OnRtnFromBankToFutureByBank");
    OnStaticRtnFromBankToFutureByBank(pRspTransfer);
}

///银行发起期货资金转银行通知
void TdSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer){
    OutputDebugString("OnRtnFromFutureToBankByBank");
    OnStaticRtnFromFutureToBankByBank(pRspTransfer);
}

///银行发起冲正银行转期货通知
void TdSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal){
    OutputDebugString("OnRtnRepealFromBankToFutureByBank");
    OnStaticRtnRepealFromBankToFutureByBank(pRspRepeal);
}

///银行发起冲正期货转银行通知
void TdSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal){
    OutputDebugString("OnRtnRepealFromFutureToBankByBank");
    OnStaticRtnRepealFromFutureToBankByBank(pRspRepeal);
}

///期货发起银行资金转期货通知
void TdSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer){
    OutputDebugString("OnRtnFromBankToFutureByFuture");
    OnStaticRtnFromBankToFutureByFuture(pRspTransfer);
}

///期货发起期货资金转银行通知
void TdSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer){
    OutputDebugString("OnRtnFromFutureToBankByFuture");
    OnStaticRtnFromFutureToBankByFuture(pRspTransfer);
}

///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void TdSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal){
    OutputDebugString("OnRtnRepealFromBankToFutureByFutureManual");
    OnStaticRtnRepealFromBankToFutureByFutureManual(pRspRepeal);
}

///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void TdSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal){
    OutputDebugString("OnRtnRepealFromFutureToBankByFutureManual");
    OnStaticRtnRepealFromFutureToBankByFutureManual(pRspRepeal);
}

///期货发起查询银行余额通知
void TdSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount){
    OutputDebugString("OnRtnQueryBankBalanceByFuture");
    OnStaticRtnQueryBankBalanceByFuture(pNotifyQueryAccount);
}

///期货发起银行资金转期货错误回报
void TdSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnBankToFutureByFuture");
    OnStaticErrRtnBankToFutureByFuture(pReqTransfer, pRspInfo);
}

///期货发起期货资金转银行错误回报
void TdSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnFutureToBankByFuture");
    OnStaticErrRtnFutureToBankByFuture(pReqTransfer, pRspInfo);
}

///系统运行时期货端手工发起冲正银行转期货错误回报
void TdSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnRepealBankToFutureByFutureManual");
    OnStaticErrRtnRepealBankToFutureByFutureManual(pReqRepeal, pRspInfo);
}

///系统运行时期货端手工发起冲正期货转银行错误回报
void TdSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnRepealFutureToBankByFutureManual");
    OnStaticErrRtnRepealFutureToBankByFutureManual(pReqRepeal, pRspInfo);
}

///期货发起查询银行余额错误回报
void TdSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo){
    OutputDebugString("OnErrRtnQueryBankBalanceByFuture");
    OnStaticErrRtnQueryBankBalanceByFuture(pReqQueryAccount, pRspInfo);
}

///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void TdSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal){
    OutputDebugString("OnRtnRepealFromBankToFutureByFuture");
    OnStaticRtnRepealFromBankToFutureByFuture(pRspRepeal);
}

///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void TdSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal){
    OutputDebugString("OnRtnRepealFromFutureToBankByFuture");
    OnStaticRtnRepealFromFutureToBankByFuture(pRspRepeal);
}

///期货发起银行资金转期货应答
void TdSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspFromBankToFutureByFuture");
    OnStaticRspFromBankToFutureByFuture(pReqTransfer, pRspInfo, nRequestID, bIsLast);
}

///期货发起期货资金转银行应答
void TdSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspFromFutureToBankByFuture");
    OnStaticRspFromFutureToBankByFuture(pReqTransfer, pRspInfo, nRequestID, bIsLast);
}

///期货发起查询银行余额应答
void TdSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
    OutputDebugString("OnRspQueryBankAccountMoneyByFuture");
    OnStaticRspQueryBankAccountMoneyByFuture(pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
}

///银行发起银期开户通知
void TdSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount){
    OutputDebugString("OnRtnOpenAccountByBank");
    OnStaticRtnOpenAccountByBank(pOpenAccount);
}

///银行发起银期销户通知
void TdSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount){
    OutputDebugString("OnRtnCancelAccountByBank");
    OnStaticRtnCancelAccountByBank(pCancelAccount);
}

///银行发起变更银行账号通知
void TdSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount){
    OutputDebugString("OnRtnChangeAccountByBank");
    OnStaticRtnChangeAccountByBank(pChangeAccount);
}