--- io.c.orig	Sat Mar 14 23:22:07 1992
+++ io.c	Sun Jan 21 20:46:00 2007
@@ -28,6 +28,17 @@
  *     need to #define VMS since it is inherent in the compiler.
  */
 
+#include <signal.h>
+#include <string.h>
+#include <stdlib.h>
+
+static on_alrm();
+static chk_arrow (register char c);
+static tload();
+static char *egetstr (char *name, char **sptr);
+static setuptty();
+
+
 /* unless you are on VMS define one of these... */
 #define UNIX
 /* #define TURBO_C */
@@ -35,8 +46,8 @@
 /* then if you defined UNIX you must use one of these ways to do non-blocking
  * tty reads
  */
-#define USE_FIONREAD
-/* #define USE_NDELAY */
+/* #define USE_FIONREAD */
+#define USE_NDELAY
 /* #define USE_ATTSELECT */
 /* #define USE_BSDSELECT */
 
@@ -56,7 +67,7 @@
 #ifdef UNIX
 #include <signal.h>
 #ifdef USE_TERMIO
-#include <termio.h>
+#include <termios.h>
 #endif
 #ifdef USE_SGTTY
 #include <sgtty.h>
@@ -73,7 +84,7 @@
 static int tloaded;
 static int ttysetup;
 #ifdef USE_TERMIO
-static struct termio orig_tio;
+static struct termios orig_tio;
 #endif
 #ifdef USE_SGTTY
 static struct sgttyb orig_sgtty;
@@ -199,11 +210,19 @@
 	    seqa[0] = c;
 	    if (l > 1) {
 		extern unsigned alarm();
+		int ch_read, ch_expected, seqa_i;
 		/* cautiously read rest of arrow sequence */
 		got_alrm = 0;
 		(void) signal (SIGALRM, on_alrm);
 		alarm(2);
-		read (0, seqa+1, l-1);
+		/* to make the arrow keys work with FreeBSD ... */
+		ch_expected = l-1;
+		seqa_i = 1;
+		while ((ch_read = read (0, seqa+seqa_i, ch_expected)) > 0 &&
+			ch_read < ch_expected) {
+		    ch_expected -= ch_read;
+		    seqa_i += ch_read;
+		}
 		alarm(0);
 		if (got_alrm)
 		    return (c);
@@ -232,7 +251,7 @@
 	}
 
 #ifdef USE_TERMIO
-	ioctl (0, TCSETA, &orig_tio);
+	tcsetattr(0, TCSANOW, &orig_tio);
 #endif
 #ifdef USE_SGTTY
 	ioctl (0, TIOCSETP, &orig_sgtty);
@@ -321,16 +340,16 @@
 setuptty()
 {
 #ifdef USE_TERMIO
-	struct termio tio;
+	struct termios tio;
 
-	ioctl (0, TCGETA, &orig_tio);
+	tcgetattr(0, &orig_tio);
 	tio = orig_tio;
 	tio.c_iflag &= ~ICRNL;	/* leave CR unchanged */
 	tio.c_oflag &= ~OPOST;	/* no output processing */
 	tio.c_lflag &= ~(ICANON|ECHO); /* no input processing, no echo */
 	tio.c_cc[VMIN] = 1;	/* return after each char */
 	tio.c_cc[VTIME] = 0;	/* no read timeout */
-	ioctl (0, TCSETA, &tio);
+	tcsetattr(0, TCSANOW, &tio);
 #endif
 #ifdef USE_SGTTY
 	struct sgttyb sg;
