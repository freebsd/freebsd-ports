--- post/src/elmerpost.h.orig	2016-07-15 11:02:59 UTC
+++ post/src/elmerpost.h
@@ -62,6 +62,7 @@
 
 #include <elmer/matc.h>
 
+#define	USE_INTERP_RESULT
 
 #if defined(MINGW32) || defined(WIN32)
 
