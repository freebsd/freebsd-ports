--- imagepool/poolassociation.cpp.orig	2018-12-12 23:25:10 UTC
+++ imagepool/poolassociation.cpp
@@ -120,7 +120,7 @@ OFCondition Association::SendObject(DcmD
 	T_DIMSE_C_StoreRSP rsp;
 
 	// check if we SOPClass and SOPInstance in dataset
-	if (!DU_findSOPClassAndInstanceInDataSet(dataset, sopClass, sopInstance))
+	if (!DU_findSOPClassAndInstanceInDataSet(dataset, sopClass, strlen(sopClass), sopInstance, strlen(sopInstance)))
 	{
 		return DIMSE_BADDATA;
 	}
