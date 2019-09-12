--- liblog/logger_write.cpp.orig	2019-07-17 19:54:09 UTC
+++ liblog/logger_write.cpp
@@ -15,12 +15,12 @@
  */
 
 #include <errno.h>
-#include <stdatomic.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/time.h>
 
-#ifdef __BIONIC__
+#if defined(__ANDROID__)
+#include <stdatomic.h>
 #include <android/set_abort_message.h>
 #endif
 
