--- src/arvrealtime.c.orig	2017-04-10 13:30:09 UTC
+++ src/arvrealtime.c
@@ -27,6 +27,8 @@
 
 ***/
 
+#include <sys/param.h>
+
 #include <arvrealtimeprivate.h>
 #include <arvdebug.h>
 #include <memory.h>
@@ -219,7 +221,12 @@ arv_rtkit_make_high_priority (GDBusConne
 #endif
 
 static pid_t _gettid(void) {
+#ifdef __linux__
         return (pid_t) syscall(SYS_gettid);
+#endif
+#ifdef BSD
+        return (pid_t) pthread_self();
+#endif
 }
 
 /**
