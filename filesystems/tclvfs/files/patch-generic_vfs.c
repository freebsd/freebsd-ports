--- generic/vfs.c.orig	2026-08-03 07:46:37 UTC
+++ generic/vfs.c
@@ -189,11 +189,7 @@ VfsFreeInternalRep(
 
 static void
 VfsFreeInternalRep(
-#if TCL_MAJOR_VERSION < 9
-		   char* clientData
-#else
 		   ClientData clientData
-#endif
 		   ) {
     VfsNativeRep *nativeRep = (VfsNativeRep*)clientData;
     if (nativeRep != NULL) {
