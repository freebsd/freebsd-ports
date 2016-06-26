--- com.amd.aparapi.jni/src/cpp/Common.h.orig	2015-09-21 01:20:25 UTC
+++ com.amd.aparapi.jni/src/cpp/Common.h
@@ -44,7 +44,7 @@
 #include <string.h>
 #include <time.h>
 
-#ifndef __APPLE__
+#if not defined __APPLE__ && not defined __FreeBSD__
 #include <malloc.h>
 #endif
 
