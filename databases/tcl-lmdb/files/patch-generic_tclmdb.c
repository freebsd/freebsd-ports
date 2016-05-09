--- generic/tclmdb.c.orig	2016-05-05 23:50:19 UTC
+++ generic/tclmdb.c
@@ -1357,11 +1357,9 @@ static int LMDB_ENV(void *cd, Tcl_Interp
       const char *zArg;
       char *path = NULL;
       mdb_mode_t mode = 0664;
-      int flags;
+      int flags = 0;
       int i = 0;
 
-      flags = MDB_FIXEDMAP;
-
       if( objc < 4 || (objc&1)!=0 ){
         Tcl_WrongNumArgs(interp, 1, objv,
         "ENV_HANDLE -path path ?-mode mode? ?-fixedmap BOOLEAN? ?-nosubdir BOOLEAN? ?-readonly BOOLEAN? ?-nosync BOOLEAN? ?-nordahead BOOLEAN? "
