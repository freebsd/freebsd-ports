--- ./unix/unixscr.c.orig	2008-05-03 13:52:03.000000000 -0400
+++ ./unix/unixscr.c	2010-01-27 13:52:46.000000000 -0500
@@ -54,7 +54,7 @@
 #define FNDELAY O_NDELAY
 #endif
 #endif
-#ifdef __SVR4
+#if defined (__SVR4) || defined(__FreeBSD__)
 # include <sys/filio.h>
 # define FNDELAY O_NONBLOCK
 #endif
@@ -339,7 +339,7 @@
     initdacbox();
 
     if (!simple_input) {
-	  signal(SIGINT,(SignalHandler)goodbye);
+	  signal(SIGINT,(sig_t)goodbye);
     }
     signal(SIGFPE, fpe_handler);
     /*
