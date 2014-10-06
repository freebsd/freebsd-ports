--- post/src/elmerpost.h.orig	2014-09-09 15:50:25.000000000 -0500
+++ post/src/elmerpost.h	2014-09-09 16:25:51.000000000 -0500
@@ -62,6 +62,7 @@
 
 #include <elmer/matc.h>
 
+#define	USE_INTERP_RESULT
 
 #if defined(MINGW32) || defined(WIN32)
 
