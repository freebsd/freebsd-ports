--- src/main.cpp.orig	2017-02-07 07:22:42 UTC
+++ src/main.cpp
@@ -272,8 +272,8 @@ void signal_act(int sig)
     fprintf(ftty, "Interrupt\n");
     if (ftty != stderr)  fprintf(stderr, "*** Interrupt\n");
 
-    static long last_sigint_time = 0;
-    long curtime;
+    static time_t last_sigint_time = 0;
+    time_t curtime;
     time(&curtime);
     bool isInsisted = (curtime - last_sigint_time <= 2); // re-pressed Ctrl-C after less than 2 secs
     if (!isInsisted && qApp != NULL) {
