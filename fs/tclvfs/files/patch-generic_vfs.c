--- generic/vfs.c.orig	2006-08-30 21:38:03.000000000 +0200
+++ generic/vfs.c	2013-09-24 10:26:34.000000000 +0200
@@ -1656,7 +1656,10 @@
     return returnVal;
 }
 
-static CONST char**
+#ifndef CONST86
+#define CONST86
+#endif
+static CONST char*CONST86 *
 VfsFileAttrStrings(pathPtr, objPtrRef)
     Tcl_Obj* pathPtr;
     Tcl_Obj** objPtrRef;
