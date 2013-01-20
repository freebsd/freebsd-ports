--- main.c.orig	2013-01-20 15:06:09.000000000 +0900
+++ main.c	2013-01-20 15:06:31.000000000 +0900
@@ -211,7 +211,9 @@
 #undef FIOCLEX
 #undef FIONCLEX
 #define setpgrp2 setpgrp
+#ifndef USE_POSIX_TERMIOS
 #include <sgtty.h>
+#endif
 #include <sys/resource.h>
 #endif
 #ifdef sco
@@ -237,7 +239,7 @@
 #define HAS_UTMP_UT_HOST
 #endif
 #else /* } !SYSV { */			/* BSD systems */
-#ifndef linux
+#if !defined(linux) && !defined(USE_POSIX_TERMIOS)
 #include <sgtty.h>
 #endif
 #include <sys/resource.h>
@@ -294,7 +296,7 @@
 #define ttyslot() 1
 #endif /* apollo */
 
-#ifdef SVR4
+#if defined(SVR4) || (defined(__FreeBSD__) && __FreeBSD_version >= 900007)
 #include <utmpx.h>
 #define setutent setutxent
 #define getutent getutxent
@@ -320,6 +322,10 @@
 int	Ptyfd;
 #endif /* PUCC_PTYD */
 
+#ifdef __FreeBSD__
+#include <libutil.h>	/* openpty() */
+#endif
+
 #ifdef sequent
 #define USE_GET_PSEUDOTTY
 #endif
@@ -1360,6 +1366,8 @@
 	d_tio.c_cc[VDISCARD] = CFLUSH;
 	d_tio.c_cc[VWERASE] = CWERASE;
 	d_tio.c_cc[VLNEXT] = CLNEXT;
+	d_tio.c_cc[VMIN] = 1;
+	d_tio.c_cc[VTIME] = 0;
 #endif /* } */
 #ifdef TIOCSLTC /* { */
         d_ltc.t_suspc = CSUSP;		/* t_suspc */
@@ -1408,6 +1416,8 @@
 	d_tio.c_cc[VQUIT] = CQUIT;		/* '^\'	*/
     	d_tio.c_cc[VEOF] = CEOF;		/* '^D'	*/
 	d_tio.c_cc[VEOL] = CEOL;		/* '^@'	*/
+	d_tio.c_cc[VMIN] = 1;
+	d_tio.c_cc[VTIME] = 0;
 #ifdef VSWTCH
 	d_tio.c_cc[VSWTCH] = CSWTCH;            /* usually '^Z' */
 #endif
@@ -1722,11 +1732,11 @@
 	        case 'u': case 'U':
 		    term->flags |= UTF8_KANJI;
 		    update_utf8mode();
-		    make_unicode_map();
 		    break;
 		default:
 		    break;
 	    }
+	    make_unicode_map();
 	}
 #endif /* KTERM_KANJIMODE */
 
@@ -1973,6 +1983,10 @@
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
@@ -2076,6 +2090,7 @@
 #endif /* __sgi or umips else */
 #endif /* USE_GET_PSEUDOTTY else */
 #endif /* ATT else */
+#endif /* !0 */
 }
 
 /*
