--- imagepool/poolfindassociation.cpp.orig	2014-01-19 07:38:17 UTC
+++ imagepool/poolfindassociation.cpp
@@ -40,8 +40,8 @@ FindAssociation::~FindAssociation() {
 	DeleteResultStack();
 }
 
-CONDITION FindAssociation::findSCU(T_ASC_Association *assoc, DcmDataset *query) {
-	CONDITION cond;
+OFCondition FindAssociation::findSCU(T_ASC_Association *assoc, DcmDataset *query) {
+	OFCondition cond;
 	DIC_US msgId = assoc->nextMsgID++;
 	T_ASC_PresentationContextID presId;
 	T_DIMSE_C_FindRQ req;
@@ -100,7 +100,7 @@ void FindAssociation::findCallback(void*
 	caller->OnResponseReceived(response);
 }
 
-CONDITION FindAssociation::SendObject(DcmDataset *dataset) {
+OFCondition FindAssociation::SendObject(DcmDataset *dataset) {
 	return findSCU(assoc, dataset);
 }
 
