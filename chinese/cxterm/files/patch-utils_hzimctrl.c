--- utils/hzimctrl.c.orig	2007-11-22 14:25:31.000000000 +0100
+++ utils/hzimctrl.c	2007-11-22 14:25:47.000000000 +0100
@@ -67,12 +67,19 @@
 #define USE_SYSV_TERMIO
 #endif /* SYSV */
 
+#ifdef __FreeBSD__
+#define USE_SYSV_TERMIO
+#define USE_TERMIOS
+#include <termios.h>
+#define termio termios
+#else /* !__FreeBSD__ */
 #include <sys/ioctl.h>
 #ifdef USE_SYSV_TERMIO
 #include <sys/termio.h>
 #else /* else not USE_SYSV_TERMIO */
 #include <sgtty.h>
 #endif	/* USE_SYSV_TERMIO */
+#endif /* __FreeBSD__ */
 
 #ifdef SYSV
 #ifdef USE_USG_PTYS
@@ -112,6 +119,11 @@
 char *setim = "\033]161;%s\007";	/* esc seq for set hz input method */
 char *setparam = "\033]162;%s\007";	/* esc seq for set input param */
 
+#ifdef CANT_OPEN_DEV_TTY
+	extern char *ttyname();
+#endif
+	static void Usage();
+
 /*
    set input method 
  */
@@ -127,10 +139,6 @@
 #endif /* USE_SYSV_TERMIO */
 	char buf[BUFSIZ];
 	char *name_of_tty;
-#ifdef CANT_OPEN_DEV_TTY
-	extern char *ttyname();
-#endif
-	static void Usage();
 
 	ptr = strrchr(myname = argv[0], '/');
 	if (ptr)
@@ -179,9 +187,13 @@
 	tty = fileno(ttyfp);
 
 #ifdef USE_SYSV_TERMIO
+#ifdef USE_TERMIOS
+	tcgetattr(tty, &tioorig);
+#else
 	ioctl (tty, TCGETA, &tioorig);
+#endif
 	tio = tioorig;
-	tio.c_iflag &= ~(ICRNL | IUCLC);
+	tio.c_iflag &= ~(ICRNL);
 	tio.c_lflag &= ~(ICANON | ECHO);
 	tio.c_cflag |= CS8;
 	tio.c_cc[VMIN] = 6;
@@ -196,7 +208,11 @@
 	signal(SIGQUIT, onintr);
 	signal(SIGTERM, onintr);
 #ifdef USE_SYSV_TERMIO
+#ifdef USE_TERMIOS
+	tcsetattr(tty, TCSADRAIN, &tio);
+#else
 	ioctl (tty, TCSETAW, &tio);
+#endif
 #else	/* not USE_SYSV_TERMIO */
 	ioctl (tty, TIOCSETP, &sg);
 #endif	/* USE_SYSV_TERMIO */
@@ -204,7 +220,11 @@
 	write(tty, buf, strlen(buf));
 
 #ifdef USE_SYSV_TERMIO
+#ifdef USE_TERMIOS
+	tcsetattr(tty, TCSADRAIN, &tioorig);
+#else
 	ioctl (tty, TCSETAW, &tioorig);
+#endif
 #else	/* not USE_SYSV_TERMIO */
 	ioctl (tty, TIOCSETP, &sgorig);
 #endif	/* USE_SYSV_TERMIO */
@@ -228,7 +248,11 @@
     int sig;
 {
 #ifdef USE_SYSV_TERMIO
+#ifdef USE_TERMIOS
+	tcsetattr(tty, TCSADRAIN, &tioorig);
+#else
 	ioctl (tty, TCSETAW, &tioorig);
+#endif
 #else	/* not USE_SYSV_TERMIO */
 	ioctl (tty, TIOCSETP, &sgorig);
 #endif	/* USE_SYSV_TERMIO */
