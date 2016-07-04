--- imagepool/poolmoveassociation.h.orig	2014-01-19 07:38:17 UTC
+++ imagepool/poolmoveassociation.h
@@ -39,7 +39,7 @@ public:
 
 	void Create(const std::string& title, const std::string& peer, int port, const std::string& ouraet, /*int ourPort,*/ const char *abstractSyntax = UID_MOVEPatientRootQueryRetrieveInformationModel/*, const char *abstractSyntaxMove = UID_MOVEPatientRootQueryRetrieveInformationModel*/);
 
-	CONDITION SendObject(DcmDataset *dataset);
+	OFCondition SendObject(DcmDataset *dataset);
 
 protected:
 
@@ -62,17 +62,17 @@ private:
 		MoveAssociation* pCaller;
 	} StoreCallbackInfo;
 
-	CONDITION moveSCU(DcmDataset *pdset);
+	OFCondition moveSCU(DcmDataset *pdset);
 	static void moveCallback(void *callbackData, T_DIMSE_C_MoveRQ *request, int responseCount, T_DIMSE_C_MoveRSP *response);
 
-	CONDITION acceptSubAssoc(T_ASC_Network *aNet, T_ASC_Association **assoc);
-	CONDITION subOpSCP(T_ASC_Association **subAssoc);
+	OFCondition acceptSubAssoc(T_ASC_Network *aNet, T_ASC_Association **assoc);
+	OFCondition subOpSCP(T_ASC_Association **subAssoc);
 	static void subOpCallback(void * pCaller, T_ASC_Network *aNet, T_ASC_Association **subAssoc);
 
-	CONDITION storeSCP(T_ASC_Association *assoc, T_DIMSE_Message *msg, T_ASC_PresentationContextID presID);
+	OFCondition storeSCP(T_ASC_Association *assoc, T_DIMSE_Message *msg, T_ASC_PresentationContextID presID);
 	static void storeSCPCallback(void *callbackData, T_DIMSE_StoreProgress *progress, T_DIMSE_C_StoreRQ *req, char *imageFileName, DcmDataset **imageDataSet, T_DIMSE_C_StoreRSP *rsp, DcmDataset **statusDetail);
 
-	CONDITION echoSCP(T_ASC_Association *assoc, T_DIMSE_Message *msg, T_ASC_PresentationContextID presID);
+	OFCondition echoSCP(T_ASC_Association *assoc, T_DIMSE_Message *msg, T_ASC_PresentationContextID presID);
 };
 
 #endif // IMAGEPOOL_MOVEASSOCIATION_H
