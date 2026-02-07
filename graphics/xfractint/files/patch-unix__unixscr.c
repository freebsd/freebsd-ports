--- unix/unixscr.c.orig	2015-08-09 13:46:52 UTC
+++ unix/unixscr.c
@@ -54,7 +54,7 @@
 #define FNDELAY O_NDELAY
 #endif
 #endif
-#ifdef __SVR4
+#if defined (__SVR4) || defined(__FreeBSD__)
 # include <sys/filio.h>
 # define FNDELAY O_NONBLOCK
 #endif
@@ -337,7 +337,7 @@ UnixInit()
     initdacbox();
 
     if (!simple_input) {
-	  signal(SIGINT,(SignalHandler)goodbye);
+	  signal(SIGINT,(sig_t)goodbye);
     }
     signal(SIGFPE, fpe_handler);
     /*
