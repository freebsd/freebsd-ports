--- src/Akai.h.orig	2017-11-19 20:27:40 UTC
+++ src/Akai.h
@@ -30,7 +30,7 @@
 # include <config.h>
 #endif
 
-#if !defined(_CARBON_) && !defined(__APPLE__) && !defined(WIN32)
+#if !defined(_CARBON_) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(WIN32)
 # define LINUX 1
 #endif
 
@@ -146,7 +146,7 @@ public:
 protected:
 #ifdef WIN32
   HANDLE mFile;
-#elif defined _CARBON_ || defined(__APPLE__) || LINUX
+#elif defined _CARBON_ || defined(__APPLE__) || defined(__FreeBSD__) || LINUX
   int mFile;
 #endif
   bool mRegularFile;
