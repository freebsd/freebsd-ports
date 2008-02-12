--- cxterm/main.c.orig	Fri Oct 25 11:44:46 2002
+++ cxterm/main.c	Fri Oct 25 11:47:13 2002
@@ -220,8 +220,13 @@
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
 #endif
 #include <sys/resource.h>
 #define HAS_UTMP_UT_HOST
@@ -968,7 +973,7 @@
 	** implementation to implementation).
 	*/
 	d_tio.c_iflag = ICRNL|IXON;
-	d_tio.c_oflag = OPOST|ONLCR|TAB3;
+	d_tio.c_oflag = OPOST|ONLCR|OXTABS;
 #if defined(macII) || defined(ATT) || defined(CRAY) || (defined(sun) && defined(SVR4)) /* { */
 #ifndef HANZI
     	d_tio.c_cflag = B9600|CS8|CREAD|PARENB|HUPCL;
@@ -1036,11 +1041,13 @@
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
@@ -1090,7 +1097,11 @@
 
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
@@ -1970,7 +1981,11 @@
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
@@ -2340,19 +2355,17 @@
 #endif /* ISTRIP */
 #endif /* HANZI */
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
 #ifndef	HANZI
@@ -2476,7 +2489,11 @@
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
