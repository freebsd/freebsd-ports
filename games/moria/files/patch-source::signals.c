$FreeBSD$

--- source/signals.c	Thu Jul 21 19:47:42 1994
+++ source/signals.c	Tue Aug  5 10:00:36 2003
@@ -89,7 +89,7 @@
 
 /*ARGSUSED*/
 #ifndef USG
-#ifdef __386BSD__
+#if defined(__386BSD__) || defined(__FreeBSD__)
 static void signal_handler(sig, code, scp)
 #else
 static int signal_handler(sig, code, scp)
@@ -217,7 +217,7 @@
 #if defined(atarist) && defined(__GNUC__)
   (void) signal(SIGTSTP, (__Sigfunc)suspend);
 #else
-#ifdef  __386BSD__
+#if defined(__386BSD__) || defined(__FreeBSD__)
   (void) signal(SIGTSTP, (sig_t)suspend);
 #else
   (void) signal(SIGTSTP, suspend);
