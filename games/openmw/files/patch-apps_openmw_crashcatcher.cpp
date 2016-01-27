--- apps/openmw/crashcatcher.cpp.orig	2016-01-12 16:11:28 UTC
+++ apps/openmw/crashcatcher.cpp
@@ -24,7 +24,7 @@
 #ifndef PR_SET_PTRACER
 #define PR_SET_PTRACER 0x59616d61
 #endif
-#elif defined (__APPLE__)
+#elif defined (__APPLE__) || defined (__FreeBSD__)
 #include <signal.h>
 #endif
 
