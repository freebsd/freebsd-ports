--- adb/sysdeps/mutex.h.orig	2016-06-23 07:04:56 UTC
+++ adb/sysdeps/mutex.h
@@ -104,4 +104,6 @@
 
 }
 
+#else
+#include <mutex>
 #endif
