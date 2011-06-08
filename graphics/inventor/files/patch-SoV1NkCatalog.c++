--- lib/nodekits/src/upgraders/SoV1NkCatalog.c++.orig	2001-09-25 02:45:47.000000000 +0200
+++ lib/nodekits/src/upgraders/SoV1NkCatalog.c++	2011-06-08 14:38:38.000000000 +0200
@@ -51,6 +51,9 @@
  _______________________________________________________________________
  */
 
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#endif
 
 #include <Inventor/misc/upgraders/SoV1NodekitCatalog.h>
 #include <Inventor/SoDB.h>
@@ -330,7 +333,7 @@
     void *castPNum;
 
     if ( partNameDict.find( (unsigned long) theName.getString(), castPNum ) )
-#if (_MIPS_SZPTR == 64 || __ia64)
+#if (_MIPS_SZPTR == 64 || __ia64 || __amd64__)
 	return ( (int) ((long) castPNum) );  // System long
 #else
 	return ( (int) castPNum );
