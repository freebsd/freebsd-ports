--- imagepool/poolfindassociation.h.orig	2014-01-19 07:38:17 UTC
+++ imagepool/poolfindassociation.h
@@ -45,7 +45,7 @@ public:
 	/**
 	Send a query object (C-Find) through association
 	*/
-	CONDITION SendObject(DcmDataset *dataset);
+	OFCondition SendObject(DcmDataset *dataset);
 
 	/**
 	Get the result stack of the last query
@@ -88,7 +88,7 @@ private:
 	/**
 	C-Find service class user
 	*/
-	CONDITION findSCU(T_ASC_Association * assoc, DcmDataset * query);
+	OFCondition findSCU(T_ASC_Association * assoc, DcmDataset * query);
 
 	/**
 	Callback function for C-Find service class user
