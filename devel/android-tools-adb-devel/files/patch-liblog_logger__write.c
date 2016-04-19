--- liblog/logger_write.c.orig	2016-04-16 00:01:39 UTC
+++ liblog/logger_write.c
@@ -15,12 +15,12 @@
  */
 
 #include <errno.h>
-#include <stdatomic.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/time.h>
 
 #ifdef __BIONIC__
+#include <stdatomic.h>
 #include <android/set_abort_message.h>
 #endif
 
