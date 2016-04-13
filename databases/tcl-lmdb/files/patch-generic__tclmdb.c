--- generic/tclmdb.c.orig	2016-02-25 12:27:48 UTC
+++ generic/tclmdb.c
@@ -26,6 +26,7 @@
  */
 #include <tcl.h>
 #include <stdio.h>
+#include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
 #ifdef USE_SYSTEM_LMDB
@@ -567,7 +568,7 @@ static int LMDB_DBI(void *cd, Tcl_Interp
     return TCL_ERROR;
   }
 
-  dbi = Tcl_GetHashValue( hashEntryPtr );
+  dbi = (MDB_dbi)Tcl_GetHashValue( hashEntryPtr );
 
   switch( (enum DBI_enum)choice ){
 
@@ -1355,7 +1356,7 @@ static int LMDB_ENV(void *cd, Tcl_Interp
     case DBENV_OPEN: {
       const char *zArg;
       char *path = NULL;
-      mode_t mode = 0664;
+      mdb_mode_t mode = 0664;
       int flags;
       int i = 0;
 
@@ -1374,7 +1375,7 @@ static int LMDB_ENV(void *cd, Tcl_Interp
         if( strcmp(zArg, "-path")==0 ){
             path = Tcl_GetStringFromObj(objv[i+1], 0);
         } else if( strcmp(zArg, "-mode")==0 ){
-            if(Tcl_GetIntFromObj(interp, objv[i+1], &mode) != TCL_OK) {
+            if(Tcl_GetIntFromObj(interp, objv[i+1], (int *)&mode) != TCL_OK) {
                 return TCL_ERROR;
             }
         } else if( strcmp(zArg, "-fixedmap")==0 ){
@@ -2063,7 +2064,7 @@ static int LMDB_MAIN(void *cd, Tcl_Inter
       pResultStr = Tcl_NewStringObj( handleName, -1 );
 
       newHashEntryPtr = Tcl_CreateHashEntry(tsdPtr->lmdb_hashtblPtr, handleName, &newvalue);
-      Tcl_SetHashValue(newHashEntryPtr, dbi);
+      Tcl_SetHashValue(newHashEntryPtr, (ClientData)(uintptr_t)dbi);
       Tcl_MutexUnlock(&myMutex);
 
       Tcl_CreateObjCommand(interp, handleName, (Tcl_ObjCmdProc *) LMDB_DBI,
