--- generic/itcl_ensemble.c.orig	Thu Oct 23 17:59:33 2003
+++ generic/itcl_ensemble.c	Thu Oct 23 18:00:52 2003
@@ -819,7 +819,7 @@
     cmdPtr->clientData = NULL;
     cmdPtr->deleteProc = DeleteEnsemble;
     cmdPtr->deleteData = cmdPtr->objClientData;
-    cmdPtr->deleted = 0;
+    cmdPtr->flags = 0;
     cmdPtr->importRefPtr = NULL;
 
     ensPart->cmdPtr = cmdPtr;
@@ -896,7 +896,7 @@
     cmdPtr->clientData = NULL;
     cmdPtr->deleteProc = deleteProc;
     cmdPtr->deleteData = (ClientData)clientData;
-    cmdPtr->deleted = 0;
+    cmdPtr->flags = 0;
     cmdPtr->importRefPtr = NULL;
 
     ensPart->cmdPtr = cmdPtr;
