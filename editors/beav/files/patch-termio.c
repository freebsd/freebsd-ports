--- termio.c.orig	2013-12-12 17:16:34.000000000 +0100
+++ termio.c	2013-12-12 17:17:40.000000000 +0100
@@ -8,11 +8,16 @@
 
 #ifdef UNIX			/* System V */
 
+#if defined(__GLIBC__) || \
+    defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#define TERMIOS 1
+#endif
+
 #include    <unistd.h>
 #include    <errno.h>
 #include    <stdio.h>
 #include    <signal.h>
-#ifdef BSD
+#if defined(BSD) && !defined(TERMIOS)
 #include    <sys/ioctl.h>
 #else
 #ifdef OS2
@@ -28,7 +33,8 @@
 #include    <sgtty.h>
 #define O_NDELAY O_NONBLOCK
 #else
-#ifdef __GLIBC__
+#ifdef TERMIOS
+#include <sys/ioctl.h>
 #include <termios.h>
 #else 
 #include <termio.h>
@@ -44,7 +50,7 @@ int kbdpoll;			/* in O_NDELAY mode      
 int kbdqp;			/* there is a char in kbdq  */
 char kbdq;			/* char we've already read  */
 
-#ifdef BSD
+#if defined(BSD) && !defined(TERMIOS)
 struct sgttyb otermb;
 struct sgttyb ntermb;
 #else
@@ -58,7 +64,7 @@ struct sgttyb otermio;		/* original term
 struct sgttyb ntermio;		/* charactoristics to use inside */
 struct tchars tchars, tcharsorig;
 #else
-#ifdef __GLIBC__
+#ifdef TERMIOS
 #include <sys/ioctl.h>
 struct termios otermio;
 struct termios ntermio;
@@ -86,8 +92,8 @@ int ncol;			/* Terminal size, columns.  
 void
 ttopen ()
 {
-#ifdef BSD
-#ifdef ULTRIX
+#if defined(BSD) && !defined(TERMIOS)
+#ifdef TIOCGWINSZ
     struct winsize ttysize;
 #else
     struct ttysize ttysize;
@@ -104,7 +110,7 @@ ttopen ()
    of the cursor                    */
     ttrow = 999;
     ttcol = 999;
-#ifdef ULTRIX
+#ifdef TIOCGWINSZ
     if (ioctl (0, TIOCGWINSZ, &ttysize) == 0)
     {
 	nrow = ttysize.ws_row;
@@ -137,8 +143,13 @@ ttopen ()
 	tchars.t_stopc = tchars.t_eofc = tchars.t_brkc = -1;
     ioctl (0, TIOCSETC, &tchars);
 #else
-#ifdef __GLIBC__
+#ifdef TERMIOS
+#ifdef TIOCGWINSZ
+    struct winsize ttysize;
+#endif
     tcgetattr(0,&otermio);
+    ntermio.c_ispeed = otermio.c_ispeed;
+    ntermio.c_ospeed = otermio.c_ospeed;
 #else
     ioctl (0, TCGETA, &otermio);/* save old settings */
     ntermio.c_line = otermio.c_line;
@@ -149,7 +160,7 @@ ttopen ()
     ntermio.c_lflag = 0;
     ntermio.c_cc[VMIN] = 1;
     ntermio.c_cc[VTIME] = 0;
-#ifdef __GLIBC__
+#ifdef TERMIOS
     tcsetattr(0,TCSANOW,&ntermio);
 #else
     ioctl (0, TCSETAW, &ntermio);	/* and activate them */
@@ -161,8 +172,17 @@ ttopen ()
     /* on all screens we are not sure of the initial position of the cursor */
     ttrow = 999;
     ttcol = 999;
-    nrow = NROW;
-    ncol = NCOL;
+#if defined(TERMIOS) && defined(TIOCGWINSZ)
+    if (ioctl (0, TIOCGWINSZ, &ttysize) == 0)
+    {
+	nrow = ttysize.ws_row;
+	ncol = ttysize.ws_col;
+    } else
+#endif
+    {
+	nrow = NROW;
+	ncol = NCOL;
+    }
 #endif /* BSD */
 }
 
@@ -174,7 +194,7 @@ ttopen ()
 void
 ttclose ()
 {
-#ifdef BSD
+#if defined(BSD) && !defined(TERMIOS)
     if (ioctl (0, TIOCSETP, &otermb) == -1)	/* restore terminal settings */
 	printf ("closing ioctl on dev 0 failure, error = %d\n", errno);
 #else
@@ -186,7 +206,7 @@ ttclose ()
 	ioctl (0, TIOCSETC, &tcharsorig) == -1)
 	printf ("closing ioctl on dev 0 failure, error = %d\n", errno);
 #else
-#ifdef __GLIBC__
+#ifdef TERMIOS
     if( tcsetattr(0,TCSANOW,&otermio) == -1)
 #else
     if (ioctl (0, TCSETAW, &otermio) == -1)	/* restore terminal settings */
