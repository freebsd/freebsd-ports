--- src/redis.c.orig	2011-11-30 14:07:01.000000000 +0400
+++ src/redis.c	2011-11-30 14:07:47.000000000 +0400
@@ -1682,6 +1682,14 @@
     return 0;
 }
 
+void bugReportStart(void) {
+    if (server.bug_report_start == 0) {
+        redisLog(REDIS_WARNING,
+            "=== REDIS BUG REPORT START: Cut & paste starting from here ===");
+        server.bug_report_start = 1;
+    }
+}
+
 #ifdef HAVE_BACKTRACE
 static void *getMcontextEip(ucontext_t *uc) {
 #if defined(__FreeBSD__)
@@ -1713,14 +1721,6 @@
 #endif
 }
 
-void bugReportStart(void) {
-    if (server.bug_report_start == 0) {
-        redisLog(REDIS_WARNING,
-            "=== REDIS BUG REPORT START: Cut & paste starting from here ===");
-        server.bug_report_start = 1;
-    }
-}
-
 static void sigsegvHandler(int sig, siginfo_t *info, void *secret) {
     void *trace[100];
     char **messages = NULL;
