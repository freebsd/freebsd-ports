--- main.c.orig	Wed Jun 21 15:49:06 2006
+++ main.c	Wed Jun 21 15:50:17 2006
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
@@ -1355,6 +1357,8 @@
 	d_tio.c_cc[VDISCARD] = CFLUSH;
 	d_tio.c_cc[VWERASE] = CWERASE;
 	d_tio.c_cc[VLNEXT] = CLNEXT;
+	d_tio.c_cc[VMIN] = 1;
+	d_tio.c_cc[VTIME] = 0;
 #endif /* } */
 #ifdef TIOCSLTC /* { */
         d_ltc.t_suspc = CSUSP;		/* t_suspc */
@@ -1403,6 +1407,8 @@
 	d_tio.c_cc[VQUIT] = CQUIT;		/* '^\'	*/
     	d_tio.c_cc[VEOF] = CEOF;		/* '^D'	*/
 	d_tio.c_cc[VEOL] = CEOL;		/* '^@'	*/
+	d_tio.c_cc[VMIN] = 1;
+	d_tio.c_cc[VTIME] = 0;
 #ifdef VSWTCH
 	d_tio.c_cc[VSWTCH] = CSWTCH;            /* usually '^Z' */
 #endif
