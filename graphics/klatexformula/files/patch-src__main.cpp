--- ./src/main.cpp.orig	2013-06-23 10:52:34.000000000 +0000
+++ ./src/main.cpp	2013-10-30 17:20:58.186667121 +0000
@@ -241,8 +241,8 @@
     fprintf(ftty, "Interrupt\n");
     if (ftty != stderr)  fprintf(stderr, "*** Interrupt\n");
 
-    static long last_sigint_time = 0;
-    long curtime;
+    static time_t last_sigint_time = 0;
+    time_t curtime;
     time(&curtime);
     bool isInsisted = (curtime - last_sigint_time <= 2); // re-pressed Ctrl-C after less than 2 secs
     if (!isInsisted && qApp != NULL) {
