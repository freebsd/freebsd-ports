--- unixscr.c.orig	Wed Apr 28 23:12:03 1999
+++ unixscr.c	Fri Oct  8 18:24:15 1999
@@ -241,7 +241,7 @@
     initdacbox();
 
     if (!simple_input) {
-	  signal(SIGINT,(__sighandler_t)goodbye);
+	  signal(SIGINT,(sig_t)goodbye);
     }
     signal(SIGFPE, fpe_handler);
     /*
@@ -2068,12 +2068,12 @@
 void
 shell_to_dos()
 {
-    __sighandler_t sigint;
+    sig_t sigint;
     char *shell;
     char *argv[2];
     int pid, donepid;
 
-    sigint = (__sighandler_t)signal(SIGINT, SIG_IGN);
+    sigint = signal(SIGINT, SIG_IGN);
     shell = getenv("SHELL");
     if (shell==NULL) {
 	shell = SHELL;
@@ -2121,7 +2121,7 @@
 	fcntl(0,F_SETFL,FNDELAY);
     }
 
-    signal(SIGINT, (__sighandler_t)sigint);
+    signal(SIGINT, sigint);
     putchar('\n');
 }
 
@@ -2146,7 +2146,7 @@
 int soon;
 {
     if (!fastmode) return;
-    signal(SIGALRM, (__sighandler_t)setredrawscreen);
+    signal(SIGALRM, (sig_t)setredrawscreen);
     if (soon) {
 	alarm(1);
     } else {
