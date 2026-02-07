--- heimdall/source/Heimdall.h.orig	2017-05-11 18:34:25 UTC
+++ heimdall/source/Heimdall.h
@@ -54,12 +54,4 @@
 
 #endif
 
-#if (!(defined _MSC_VER) || (_MSC_VER < 1700))
-
-#ifndef nullptr
-#define nullptr 0
-#endif
-
-#endif
-
 #endif
