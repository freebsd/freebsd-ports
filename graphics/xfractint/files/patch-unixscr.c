--- unixscr.c.orig	Mon Apr  8 19:33:28 2002
+++ unixscr.c	Mon Sep  3 16:41:27 2007
@@ -42,7 +42,7 @@
 #ifdef LINUX
 #define FNDELAY O_NDELAY
 #endif
-#ifdef __SVR4
+#if defined (__SVR4) || defined(__FreeBSD__)
 # include <sys/filio.h>
 # define FNDELAY O_NONBLOCK
 #endif
@@ -257,7 +257,7 @@
     initdacbox();
 
     if (!simple_input) {
-	  signal(SIGINT,(SignalHandler)goodbye);
+	  signal(SIGINT,(sig_t)goodbye);
     }
     signal(SIGFPE, fpe_handler);
     /*
@@ -2277,12 +2277,12 @@
 void
 shell_to_dos()
 {
-    SignalHandler sigint;
+    sig_t sigint;
     char *shell;
     char *argv[2];
     int pid, donepid;
 
-    sigint = (SignalHandler)signal(SIGINT, SIG_IGN);
+    sigint = (sig_t)signal(SIGINT, SIG_IGN);
     shell = getenv("SHELL");
     if (shell==NULL) {
 	shell = SHELL;
@@ -2330,7 +2330,7 @@
 	fcntl(0,F_SETFL,FNDELAY);
     }
 
-    signal(SIGINT, (SignalHandler)sigint);
+    signal(SIGINT, (sig_t)sigint);
     putchar('\n');
 }
 
@@ -2355,7 +2355,7 @@
 int soon;
 {
     if (!fastmode) return;
-    signal(SIGALRM, (SignalHandler)setredrawscreen);
+    signal(SIGALRM, (sig_t)setredrawscreen);
     if (soon) {
 	alarm(1);
     } else {
