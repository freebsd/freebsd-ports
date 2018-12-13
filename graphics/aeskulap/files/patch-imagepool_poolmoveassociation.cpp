--- imagepool/poolmoveassociation.cpp.orig	2018-12-12 23:21:04 UTC
+++ imagepool/poolmoveassociation.cpp
@@ -310,7 +310,7 @@ void MoveAssociation::storeSCPCallback(v
 		*/
 		if (rsp->DimseStatus == STATUS_Success) {
 			/* which SOP class and SOP instance ? */
-			if (! DU_findSOPClassAndInstanceInDataSet(cbdata->dataset, sopClass, sopInstance)) {
+			if (! DU_findSOPClassAndInstanceInDataSet(cbdata->dataset, sopClass, strlen(sopClass), sopInstance, strlen(sopInstance))) {
 				rsp->DimseStatus = STATUS_STORE_Error_CannotUnderstand;
 			}
 			else if (strcmp(sopClass, req->AffectedSOPClassUID) != 0) {
