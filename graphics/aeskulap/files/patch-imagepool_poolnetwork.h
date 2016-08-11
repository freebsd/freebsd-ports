--- imagepool/poolnetwork.h.orig	2014-01-19 07:38:17 UTC
+++ imagepool/poolnetwork.h
@@ -43,17 +43,17 @@ public:
 	/**
 	Initialize the dicom network
 	*/
-	CONDITION InitializeNetwork(int timeout=20, int port = 0);
+	OFCondition InitializeNetwork(int timeout=20, int port = 0);
 
 	/**
 	Drop the dicom network
 	*/
-	CONDITION DropNetwork();
+	OFCondition DropNetwork();
 
 	/**
 	Connect an association to the specified host
 	*/
-	CONDITION ConnectAssociation(Association* assoc, int lossy = 0);
+	OFCondition ConnectAssociation(Association* assoc, int lossy = 0);
 
 	/**
 	Send C-Echo request to dicom node
@@ -80,12 +80,12 @@ private:
 	/**
 	Add all possible presentation contexts to association parameters
 	*/
-	static CONDITION addAllStoragePresentationContexts(T_ASC_Parameters *params, bool bProposeCompression = true, int lossy = 0);
+	static OFCondition addAllStoragePresentationContexts(T_ASC_Parameters *params, bool bProposeCompression = true, int lossy = 0);
 
 	/**
 	Connect to a host and try to establish an association
 	*/
-	CONDITION ASC_ConnectAssociation(Association* assoc, const std::string& peerTitle, const std::string& peer, int port, const std::string& ouraet, const char *abstractSyntax = NULL, int lossy = 0);
+	OFCondition ASC_ConnectAssociation(Association* assoc, const std::string& peerTitle, const std::string& peer, int port, const std::string& ouraet, const char *abstractSyntax = NULL, int lossy = 0);
 
 	/**
 	THE dicom network
