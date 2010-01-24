--- main.c.orig	2010-01-25 01:02:47.051647000 +0900
+++ main.c	2010-01-25 01:03:35.081557857 +0900
@@ -210,7 +210,9 @@
 #undef FIOCLEX
 #undef FIONCLEX
 #define setpgrp2 setpgrp
+#ifndef USE_POSIX_TERMIOS
 #include <sgtty.h>
+#endif
 #include <sys/resource.h>
 #endif
 #ifdef sco
@@ -236,7 +238,7 @@
 #define HAS_UTMP_UT_HOST
 #endif
 #else /* } !SYSV { */			/* BSD systems */
-#ifndef linux
+#if !defined(linux) && !defined(USE_POSIX_TERMIOS)
 #include <sgtty.h>
 #endif
 #include <sys/resource.h>
@@ -293,7 +295,7 @@
 #define ttyslot() 1
 #endif /* apollo */
 
-#ifdef SVR4
+#if defined(SVR4) || (defined(__FreeBSD__) && __FreeBSD_version >= 900007)
 #include <utmpx.h>
 #define setutent setutxent
 #define getutent getutxent
@@ -319,6 +321,10 @@
 int	Ptyfd;
 #endif /* PUCC_PTYD */
 
+#ifdef __FreeBSD__
+#include <libutil.h>	/* openpty() */
+#endif
+
 #ifdef sequent
 #define USE_GET_PSEUDOTTY
 #endif
@@ -1355,6 +1361,8 @@
 	d_tio.c_cc[VDISCARD] = CFLUSH;
 	d_tio.c_cc[VWERASE] = CWERASE;
 	d_tio.c_cc[VLNEXT] = CLNEXT;
+	d_tio.c_cc[VMIN] = 1;
+	d_tio.c_cc[VTIME] = 0;
 #endif /* } */
 #ifdef TIOCSLTC /* { */
         d_ltc.t_suspc = CSUSP;		/* t_suspc */
@@ -1403,6 +1411,8 @@
 	d_tio.c_cc[VQUIT] = CQUIT;		/* '^\'	*/
     	d_tio.c_cc[VEOF] = CEOF;		/* '^D'	*/
 	d_tio.c_cc[VEOL] = CEOL;		/* '^@'	*/
+	d_tio.c_cc[VMIN] = 1;
+	d_tio.c_cc[VTIME] = 0;
 #ifdef VSWTCH
 	d_tio.c_cc[VSWTCH] = CSWTCH;            /* usually '^Z' */
 #endif
@@ -1963,6 +1973,10 @@
 get_pty (pty)
     int *pty;
 {
+#if 1
+    int tty;
+    return (openpty(pty, &tty, ttydev, NULL, NULL));
+#else
 #ifdef __osf__
     int tty;
     return (openpty(pty, &tty, ttydev, NULL, NULL));
@@ -2066,6 +2080,7 @@
 #endif /* __sgi or umips else */
 #endif /* USE_GET_PSEUDOTTY else */
 #endif /* ATT else */
+#endif /* !0 */
 }
 
 /*
