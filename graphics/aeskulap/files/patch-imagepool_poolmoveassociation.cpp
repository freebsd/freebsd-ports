--- imagepool/poolmoveassociation.cpp.orig	2014-01-19 07:38:17 UTC
+++ imagepool/poolmoveassociation.cpp
@@ -68,7 +68,7 @@ void MoveAssociation::Create(const std::
 	Association::Create(title, peer, port, ouraet, abstractSyntax);
 }
 
-CONDITION MoveAssociation::SendObject(DcmDataset *dataset) {
+OFCondition MoveAssociation::SendObject(DcmDataset *dataset) {
 	return moveSCU(dataset);	
 }
 
@@ -79,8 +79,8 @@ void MoveAssociation::OnAddPresentationC
 	ASC_addPresentationContext(params, 5, m_abstractSyntax, mpeg_transfer, DIM_OF(mpeg_transfer));
 }
 
-CONDITION MoveAssociation::moveSCU(DcmDataset *pdset) {
-	CONDITION cond;
+OFCondition MoveAssociation::moveSCU(DcmDataset *pdset) {
+	OFCondition cond;
 	T_ASC_PresentationContextID presId;
 	T_DIMSE_C_MoveRQ req;
 	T_DIMSE_C_MoveRSP rsp;
@@ -161,8 +161,8 @@ void MoveAssociation::subOpCallback(void
 	}
 }
 
-CONDITION MoveAssociation::acceptSubAssoc(T_ASC_Network *aNet, T_ASC_Association **assoc) {
-	CONDITION cond = ASC_NORMAL;
+OFCondition MoveAssociation::acceptSubAssoc(T_ASC_Network *aNet, T_ASC_Association **assoc) {
+	OFCondition cond = EC_Normal;
 	const char* knownAbstractSyntaxes[] = { UID_VerificationSOPClass };
 	const char* transferSyntaxes[] = { UID_JPEGProcess14SV1TransferSyntax, NULL, NULL, UID_LittleEndianImplicitTransferSyntax, UID_MPEG2MainProfileAtMainLevelTransferSyntax };
 
@@ -222,7 +222,7 @@ CONDITION MoveAssociation::acceptSubAsso
 	
 }
 
-CONDITION MoveAssociation::subOpSCP(T_ASC_Association **subAssoc) {
+OFCondition MoveAssociation::subOpSCP(T_ASC_Association **subAssoc) {
 	T_DIMSE_Message msg;
 	T_ASC_PresentationContextID presID;
 
@@ -269,8 +269,8 @@ CONDITION MoveAssociation::subOpSCP(T_AS
 	return cond;
 }
 
-CONDITION MoveAssociation::storeSCP(T_ASC_Association *assoc, T_DIMSE_Message *msg, T_ASC_PresentationContextID presID) {
-	CONDITION cond;
+OFCondition MoveAssociation::storeSCP(T_ASC_Association *assoc, T_DIMSE_Message *msg, T_ASC_PresentationContextID presID) {
+	OFCondition cond;
 	T_DIMSE_C_StoreRQ* req;
 	DcmDataset *dset = new DcmDataset;
 
@@ -328,8 +328,8 @@ void MoveAssociation::storeSCPCallback(v
 
 }
 
-CONDITION MoveAssociation::echoSCP(T_ASC_Association *assoc, T_DIMSE_Message *msg, T_ASC_PresentationContextID presID) {
-	CONDITION cond;
+OFCondition MoveAssociation::echoSCP(T_ASC_Association *assoc, T_DIMSE_Message *msg, T_ASC_PresentationContextID presID) {
+	OFCondition cond;
 
 	// the echo succeeded !!
 	cond = DIMSE_sendEchoResponse(assoc, presID, &msg->msg.CEchoRQ, STATUS_Success, NULL);
