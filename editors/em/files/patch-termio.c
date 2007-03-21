--- termio.c	Thu May  2 13:52:00 1996
+++ termio.c	Sat Mar 17 16:53:22 2007
@@ -41,16 +41,21 @@
 int nxtchar = -1;	/* character held from type ahead    */
 #endif
 
+#undef USG
+#define USG 1
+#undef BSD
+#define BSD 0
+
 #if	USG			/* System V */
 #include	<signal.h>
-#include	<termio.h>
+#include	<termios.h>
 #include	<fcntl.h>
 int kbdflgs;			/* saved keyboard fd flags	*/
 int kbdpoll;			/* in O_NDELAY mode			*/
 int kbdqp;			/* there is a char in kbdq	*/
 char kbdq;			/* char we've already read	*/
-struct	termio	otermio;	/* original terminal characteristics */
-struct	termio	ntermio;	/* charactoristics to use inside */
+struct	termios	otermio;	/* original terminal characteristics */
+struct	termios	ntermio;	/* charactoristics to use inside */
 #if	XONXOFF
 #define XXMASK	0016000
 #endif
@@ -154,7 +159,7 @@
 #endif
 
 #if	USG
-	ioctl(0, TCGETA, &otermio);	/* save old settings */
+	tcgetattr(0, &otermio);		/* save old settings */
 	ntermio.c_iflag = 0;		/* setup new settings */
 #if	XONXOFF
 	ntermio.c_iflag = otermio.c_iflag & XXMASK;	/* save XON/XOFF P.K. */
@@ -162,11 +167,10 @@
 	ntermio.c_oflag = 0;
 	ntermio.c_cflag = otermio.c_cflag;
 	ntermio.c_lflag = 0;
-	ntermio.c_line = otermio.c_line;
 	ntermio.c_cc[VMIN] = 1;
 	ntermio.c_cc[VTIME] = 0;
 #if 	PKCODE
-	ioctl(0, TCSETAW, &ntermio);	/* and activate them */
+	tcsetattr(0, TCSANOW, &ntermio); /* and activate them */
 #else
 	ioctl(0, TCSETA, &ntermio);	/* and activate them */
 #endif
@@ -244,7 +248,7 @@
 
 #if	USG
 #if	PKCODE
-	ioctl(0, TCSETAW, &otermio);	/* restore terminal settings */
+	tcsetattr(0, TCSANOW, &otermio); /* and activate them */
 #else
 	ioctl(0, TCSETA, &otermio);	/* restore terminal settings */
 #endif
