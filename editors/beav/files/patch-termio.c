--- termio.c
+++ termio.c
@@ -14,6 +14,9 @@
 #include    <signal.h>
 #ifdef BSD
 #include    <sys/ioctl.h>
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+#include <sys/ioctl_compat.h>
+#endif
 #else
 #ifdef OS2
 #ifndef __EMX__
@@ -44,7 +47,7 @@
 int kbdqp;			/* there is a char in kbdq  */
 char kbdq;			/* char we've already read  */
 
-#ifdef BSD
+#if 0
 struct sgttyb otermb;
 struct sgttyb ntermb;
 #else
@@ -58,8 +61,8 @@
 struct sgttyb ntermio;		/* charactoristics to use inside */
 struct tchars tchars, tcharsorig;
 #else
-#ifdef __GLIBC__
-#include <sys/ioctl.h>
+#if 1
+#include <termios.h>
 struct termios otermio;
 struct termios ntermio;
 #else
@@ -86,7 +89,7 @@
 void
 ttopen ()
 {
-#ifdef BSD
+#if 0
 #ifdef ULTRIX
     struct winsize ttysize;
 #else
@@ -137,7 +140,9 @@
 	tchars.t_stopc = tchars.t_eofc = tchars.t_brkc = -1;
     ioctl (0, TIOCSETC, &tchars);
 #else
-#ifdef __GLIBC__
+    struct winsize ttysize;
+
+#if 1
     tcgetattr(0,&otermio);
 #else
     ioctl (0, TCGETA, &otermio);/* save old settings */
@@ -149,7 +154,7 @@
     ntermio.c_lflag = 0;
     ntermio.c_cc[VMIN] = 1;
     ntermio.c_cc[VTIME] = 0;
-#ifdef __GLIBC__
+#if 1
     tcsetattr(0,TCSANOW,&ntermio);
 #else
     ioctl (0, TCSETAW, &ntermio);	/* and activate them */
@@ -161,8 +166,14 @@
     /* on all screens we are not sure of the initial position of the cursor */
     ttrow = 999;
     ttcol = 999;
-    nrow = NROW;
-    ncol = NCOL;
+    if (ioctl (0, TIOCGWINSZ, &ttysize) == 0)
+    {
+	nrow = ttysize.ws_row;
+	ncol = ttysize.ws_col;
+    } else {
+	nrow = NROW;
+	ncol = NCOL;
+    }
 #endif /* BSD */
 }
 
@@ -174,7 +185,7 @@
 void
 ttclose ()
 {
-#ifdef BSD
+#if 0
     if (ioctl (0, TIOCSETP, &otermb) == -1)	/* restore terminal settings */
 	printf ("closing ioctl on dev 0 failure, error = %d\n", errno);
 #else
@@ -186,7 +197,7 @@
 	ioctl (0, TIOCSETC, &tcharsorig) == -1)
 	printf ("closing ioctl on dev 0 failure, error = %d\n", errno);
 #else
-#ifdef __GLIBC__
+#if 1
     if( tcsetattr(0,TCSANOW,&otermio) == -1)
 #else
     if (ioctl (0, TCSETAW, &otermio) == -1)	/* restore terminal settings */
