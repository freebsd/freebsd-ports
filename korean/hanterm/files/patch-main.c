--- main.c.orig	Fri Oct 25 12:00:42 2002
+++ main.c	Fri Oct 25 12:01:43 2002
@@ -221,8 +221,13 @@
 #define HAS_UTMP_UT_HOST
 #endif
 #else /* SYSV */
-#ifndef linux
-#include <sgtty.h>
+#ifdef __FreeBSD__
+#include <termios.h>
+#define USE_TERMIOS
+#define USE_TERMINFO
+#define USE_SYSV_TERMIO
+#define termio termios
+#define USE_POSIX_WAIT
 #endif
 #include <sys/resource.h>
 #define HAS_UTMP_UT_HOST
@@ -1056,11 +1061,13 @@
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
 #ifdef sgi
         d_tio.c_cflag &= ~(HUPCL|PARENB);
         d_tio.c_iflag |= BRKINT|ISTRIP|IGNPAR;
@@ -1111,7 +1118,11 @@
 
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
@@ -2021,7 +2032,11 @@
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
@@ -2389,19 +2404,17 @@
 		    tio.c_iflag &= ~(INLCR|IGNCR|ISTRIP);
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
 		    /* dkim@surecom.com */
 		    tio.c_cflag &= ~CSIZE;
@@ -2512,7 +2525,11 @@
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
 		    sg.sg_flags &= ~(ALLDELAY | XTABS | CBREAK | RAW);
