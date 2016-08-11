--- imagepool/poolnetwork.cpp.orig	2014-01-19 07:38:17 UTC
+++ imagepool/poolnetwork.cpp
@@ -42,8 +42,8 @@ Network::~Network() {
 	DropNetwork();
 }
 
-CONDITION Network::ConnectAssociation(Association* assoc, int lossy) {
-	CONDITION cond;
+OFCondition Network::ConnectAssociation(Association* assoc, int lossy) {
+	OFCondition cond;
 
 	cond = ASC_ConnectAssociation(
 						assoc,
@@ -54,7 +54,7 @@ CONDITION Network::ConnectAssociation(As
 						assoc->m_abstractSyntax,
 						lossy);
 
-	if (!SUCCESS(cond)) {
+	if (!cond.good()) {
 		assoc->Drop(cond);
 		return cond;
 	}
@@ -65,7 +65,7 @@ CONDITION Network::ConnectAssociation(As
 	return cond;
 }
 
-CONDITION Network::InitializeNetwork(int timeout, int port) {
+OFCondition Network::InitializeNetwork(int timeout, int port) {
 #ifdef _WIN32
 	WORD wVersionRequested;
 	WSADATA wsaData;
@@ -78,9 +78,9 @@ CONDITION Network::InitializeNetwork(int
 	return ASC_initializeNetwork(NET_ACCEPTORREQUESTOR, port, timeout, &net);
 }
 
-CONDITION Network::DropNetwork()
+OFCondition Network::DropNetwork()
 {
-	CONDITION cond = ASC_dropNetwork(&net);
+	OFCondition cond = ASC_dropNetwork(&net);
 	net = NULL;
 
 #ifdef _WIN32
@@ -90,9 +90,9 @@ CONDITION Network::DropNetwork()
 	return cond;
 }
 
-CONDITION Network::ASC_ConnectAssociation(Association* assoc, const std::string& peerTitle, const std::string& peer, int port, const std::string& ouraet, const char *abstractSyntax, int lossy)
+OFCondition Network::ASC_ConnectAssociation(Association* assoc, const std::string& peerTitle, const std::string& peer, int port, const std::string& ouraet, const char *abstractSyntax, int lossy)
 {
-    CONDITION cond;
+    OFCondition cond;
     T_ASC_Parameters *params;
 	bool bProposeCompression = assoc->GetProposeCompression();
 
@@ -100,7 +100,7 @@ CONDITION Network::ASC_ConnectAssociatio
     DIC_NODENAME localHost;
 
     cond = ASC_createAssociationParameters(&params, ASC_DEFAULTMAXPDU);
-    if (!SUCCESS(cond)) 
+    if (!cond.good()) 
 	{
 		return cond;
     }
@@ -155,9 +155,9 @@ CONDITION Network::ASC_ConnectAssociatio
 
     /* create association */
     cond = ASC_requestAssociation(net, params, &(assoc->assoc));
-    if (cond != ASC_NORMAL)
+    if (cond != EC_Normal)
 	{
-		if (cond == ASC_ASSOCIATIONREJECTED) 
+		if (cond == DUL_ASSOCIATIONREJECTED) 
 		{
 			T_ASC_RejectParameters rej;
 
@@ -178,12 +178,12 @@ CONDITION Network::ASC_ConnectAssociatio
 		return cond;
     }
 
-	return ASC_NORMAL;
+	return EC_Normal;
 }
 
-CONDITION Network::addAllStoragePresentationContexts(T_ASC_Parameters *params, bool bProposeCompression, int lossy)
+OFCondition Network::addAllStoragePresentationContexts(T_ASC_Parameters *params, bool bProposeCompression, int lossy)
 {
-    CONDITION cond = ASC_NORMAL;
+    OFCondition cond = EC_Normal;
     int i;
     int pid = 1;
 
@@ -232,7 +232,7 @@ CONDITION Network::addAllStoragePresenta
 	}
 
 	/* the array of Storage SOP Class UIDs comes from dcuid.h */
-	for (i=0; i<numberOfAllDcmStorageSOPClassUIDs && SUCCESS(cond); i++) {
+	for (i=0; i<numberOfAllDcmStorageSOPClassUIDs && cond.good(); i++) {
 		cond = ASC_addPresentationContext(params, pid, dcmAllStorageSOPClassUIDs[i], transferSyntaxes, transferSyntaxes_count);
 		pid += 2;	/* only odd presentation context id's */
 	}
