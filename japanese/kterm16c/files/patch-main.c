Place the following patch in the files/ directory.

--- main.c	2008-01-28 08:42:32.000000000 +0100
+++ main.c	2008-01-28 08:42:25.000000000 +0100
@@ -224,8 +224,14 @@
 #define HAS_UTMP_UT_HOST
 #endif
 #else /* } !SYSV { */			/* BSD systems */
-#ifndef linux
-#include <sgtty.h>
+#ifdef __FreeBSD__
+#include <termios.h>
+#define USE_TERMIOS
+#define USE_TERMINFO
+#define USE_SYSV_TERMIO
+#define termio termios
+#define USE_POSIX_WAIT
+#define HAS_POSIX_SAVED_IDS
 #endif
 #include <sys/resource.h>
 #define HAS_UTMP_UT_HOST
@@ -249,11 +255,6 @@
 #include <sys/param.h>	/* for NOFILE */
 #endif
 
-#if (BSD >= 199103)
-#define USE_POSIX_WAIT
-#define HAS_POSIX_SAVED_IDS
-#endif
-
 #include <stdio.h>
 #include <errno.h>
 #include <setjmp.h>
@@ -1293,7 +1294,7 @@
 	** implementation to implementation).
 	*/
 	d_tio.c_iflag = ICRNL|IXON;
-	d_tio.c_oflag = OPOST|ONLCR|TAB3;
+	d_tio.c_oflag = OPOST|ONLCR|OXTABS;
 #if defined(macII) || defined(ATT) || defined(CRAY) /* { */
     	d_tio.c_cflag = B9600|CS8|CREAD|PARENB|HUPCL;
     	d_tio.c_lflag = ISIG|ICANON|ECHO|ECHOE|ECHOK;
@@ -1349,11 +1350,13 @@
 #ifdef ECHOCTL
 	d_tio.c_lflag |= ECHOCTL|IEXTEN;
 #endif
+#ifndef __FreeBSD__
 #ifdef NTTYDISC
         d_tio.c_line = NTTYDISC;
 #else
 	d_tio.c_line = 0;
 #endif	
+#endif
 #ifdef __sgi
         d_tio.c_cflag &= ~(HUPCL|PARENB);
         d_tio.c_iflag |= BRKINT|ISTRIP|IGNPAR;
@@ -1403,7 +1406,11 @@
 
 	    for (i = 0; i <= 2; i++) {
 		struct termio deftio;
+#ifdef USE_TERMIOS
+		if (tcgetattr(i, &deftio) == 0) {
+#else
 		if (ioctl (i, TCGETA, &deftio) == 0) {
+#endif
 		    d_tio.c_cc[VINTR] = deftio.c_cc[VINTR];
 		    d_tio.c_cc[VQUIT] = deftio.c_cc[VQUIT];
 		    d_tio.c_cc[VERASE] = deftio.c_cc[VERASE];
@@ -2370,7 +2377,11 @@
 				lmode = d_lmode;
 #endif	/* TIOCLSET */
 #ifdef USE_SYSV_TERMIO
+#ifdef USE_TERMIOS
+                        if(tcgetattr(tty, &tio) == -1)
+#else
 		        if(ioctl(tty, TCGETA, &tio) == -1)
+#endif
 			        tio = d_tio;
 
 #else	/* not USE_SYSV_TERMIO */
@@ -2770,19 +2781,17 @@
 		    tio.c_iflag &= ~(INLCR|IGNCR);
 		    tio.c_iflag |= ICRNL;
 		    /* ouput: cr->cr, nl is not return, no delays, ln->cr/nl */
-		    tio.c_oflag &=
-		     ~(OCRNL|ONLRET|NLDLY|CRDLY|TABDLY|BSDLY|VTDLY|FFDLY);
+		    tio.c_oflag &= ~(OCRNL|ONLRET);
 		    tio.c_oflag |= ONLCR;
 #ifdef OPOST
 		    tio.c_oflag |= OPOST;
 #endif /* OPOST */		    
 #ifdef BAUD_0
 		    /* baud rate is 0 (don't care) */
-		    tio.c_cflag &= ~(CBAUD);
+		    cfsetspeed(&tio, 0);
 #else	/* !BAUD_0 */
 		    /* baud rate is 9600 (nice default) */
-		    tio.c_cflag &= ~(CBAUD);
-		    tio.c_cflag |= B9600;
+		    cfsetspeed(&tio, 9600);
 #endif	/* !BAUD_0 */
 		    tio.c_cflag &= ~CSIZE;
 		    if (screen->input_eight_bits)
@@ -2895,7 +2904,11 @@
 		    if (ioctl (tty, TIOCLSET, (char *)&lmode) == -1)
 			    HsSysError(cp_pipe[1], ERROR_TIOCLSET);
 #endif	/* TIOCLSET */
+#ifdef USE_TERMIOS
+		    if (tcsetattr(tty, TCSANOW, &tio) == -1)
+#else
 		    if (ioctl (tty, TCSETA, &tio) == -1)
+#endif
 			    HsSysError(cp_pipe[1], ERROR_TIOCSETP);
 #else	/* USE_SYSV_TERMIO */
 #ifdef KTERM
