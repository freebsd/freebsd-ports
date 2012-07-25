--- ./src/lib/fcitx-utils/utils.c~	2012-07-17 15:21:04.000000000 -0500
+++ ./src/lib/fcitx-utils/utils.c	2012-07-18 00:14:56.901797676 -0500
@@ -113,13 +113,13 @@ void fcitx_utils_init_as_daemon()
         exit(0);
     }
     setsid();
-    sighandler_t oldint = signal(SIGINT, SIG_IGN);
-    sighandler_t oldhup  =signal(SIGHUP, SIG_IGN);
-    sighandler_t oldquit = signal(SIGQUIT, SIG_IGN);
-    sighandler_t oldpipe = signal(SIGPIPE, SIG_IGN);
-    sighandler_t oldttou = signal(SIGTTOU, SIG_IGN);
-    sighandler_t oldttin = signal(SIGTTIN, SIG_IGN);
-    sighandler_t oldchld = signal(SIGCHLD, SIG_IGN);
+    sig_t oldint = signal(SIGINT, SIG_IGN);
+    sig_t oldhup  =signal(SIGHUP, SIG_IGN);
+    sig_t oldquit = signal(SIGQUIT, SIG_IGN);
+    sig_t oldpipe = signal(SIGPIPE, SIG_IGN);
+    sig_t oldttou = signal(SIGTTOU, SIG_IGN);
+    sig_t oldttin = signal(SIGTTIN, SIG_IGN);
+    sig_t oldchld = signal(SIGCHLD, SIG_IGN);
     if (fork() > 0)
         exit(0);
     chdir("/");
