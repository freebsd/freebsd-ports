--- imagepool/poolassociation.cpp.orig	2014-01-19 07:38:17 UTC
+++ imagepool/poolassociation.cpp
@@ -72,24 +72,24 @@ Association::~Association()
 		Drop();
 }
 
-CONDITION Association::Drop(CONDITION cond) {
+OFCondition Association::Drop(OFCondition cond) {
 	// tear down association
-	if(cond == DIMSE_NORMAL) {
+	if(cond == EC_Normal) {
 		/* release association */
 		cond = ASC_releaseAssociation(assoc);
 	}
-	else if(cond == DIMSE_PEERREQUESTEDRELEASE) {
+	else if(cond == DUL_PEERREQUESTEDRELEASE) {
 		cond = ASC_abortAssociation(assoc);
-		if (SUCCESS(cond)) {
+		if (cond.good()) {
 			return cond;
 		}
 	}
-	else if(cond == DIMSE_PEERABORTEDASSOCIATION) {
+	else if(cond == DUL_PEERABORTEDASSOCIATION) {
 		return cond;
 	}
 	else {
 		cond = ASC_abortAssociation(assoc);
-		if (SUCCESS(cond)) {
+		if (cond.good()) {
 			return cond;
 		}
 	}
@@ -99,7 +99,7 @@ CONDITION Association::Drop(CONDITION co
 }
 
 void Association::Destroy() {
-	CONDITION cond = ASC_destroyAssociation(&assoc);
+	OFCondition cond = ASC_destroyAssociation(&assoc);
 
 	dcmNet = NULL;
 	assoc = NULL;
@@ -110,8 +110,8 @@ void Association::Destroy() {
 
 }
 
-CONDITION Association::SendObject(DcmDataset *dataset) {
-	CONDITION cond;
+OFCondition Association::SendObject(DcmDataset *dataset) {
+	OFCondition cond;
 	DcmDataset *statusDetail = NULL;
 
 	T_DIMSE_C_StoreRQ req;
@@ -163,7 +163,7 @@ CONDITION Association::SendObject(DcmDat
 	if(opt_oxferSyn.getXfer() != ori_oxferSyn) {
 		std::cout << "Converting object to accepted transfer-syntax " << opt_oxferSyn.getXferName() << std::endl;
 	
-		CONDITION cond;
+		OFCondition cond;
 		// create RepresentationParameter
 		DJ_RPLossless rp_lossless(6, 0);
 		DJ_RPLossy rp_lossy(m_CompressionQuality);
@@ -172,10 +172,18 @@ CONDITION Association::SendObject(DcmDat
 		
 		const DcmRepresentationParameter *rp = NULL;
 
+#if 0
+		if(opt_oxferSyn.getXfer() == EXS_JPEGProcess14SV1 || opt_oxferSyn.getXfer() == EXS_JPEGProcess14) {
+#else
 		if(opt_oxferSyn.getXfer() == EXS_JPEGProcess14SV1TransferSyntax || opt_oxferSyn.getXfer() == EXS_JPEGProcess14TransferSyntax) {
+#endif
 			rp = &rp_lossless;
 		}
+#if 0
+		else if(opt_oxferSyn.getXfer() == EXS_JPEGProcess1 || opt_oxferSyn.getXfer() == EXS_JPEGProcess2_4) {
+#else
 		else if(opt_oxferSyn.getXfer() == EXS_JPEGProcess1TransferSyntax || opt_oxferSyn.getXfer() == EXS_JPEGProcess2_4TransferSyntax) {
+#endif
 			rp = &rp_lossy;
 		}
 
@@ -232,15 +240,15 @@ CONDITION Association::SendObject(DcmDat
 		delete statusDetail;
 	}
 
-	if (cond != DIMSE_NORMAL)
+	if (cond != EC_Normal)
 	{
 		return cond;
 	}
 
-	return (rsp.DimseStatus == STATUS_Success) ? DIMSE_NORMAL : DIMSE_BADDATA;
+	return (rsp.DimseStatus == STATUS_Success) ? EC_Normal : DIMSE_BADDATA;
 }
 
-CONDITION Association::SendObject(DcmFileFormat *dcmff)
+OFCondition Association::SendObject(DcmFileFormat *dcmff)
 {
 	DcmDataset* dataset = dcmff->getDataset();
 	return SendObject(dataset);
@@ -334,7 +342,7 @@ Network* Association::GetNetwork()
 	return dcmNet;
 }
 
-CONDITION Association::Connect(Network *network, int lossy)
+OFCondition Association::Connect(Network *network, int lossy)
 {
 	dcmNet = network;
 	return network->ConnectAssociation(this, lossy);
