The following patch seems to fix celvis on my machine. Just place it in
the files/ directory.

--- curses.c.orig	1991-09-21 21:42:07 UTC
+++ curses.c
@@ -17,8 +17,13 @@
 #include "config.h"
 #include "vi.h"
 
+#undef BSD
+#undef UNIXV
+#define BSD	0
+#define UNIXV	1
+
 #if UNIXV
-# include	<termio.h>
+# include	<termios.h>
 #endif
 
 #if BSD || UNIX7 || MINIX
@@ -86,8 +91,8 @@ char	ERASEKEY;	/* backspace key taken from ioctl struc
 char	ERASEKEY;	/* backspace key taken from ioctl structure */
 
 #if UNIXV
-static struct termio	oldtermio;	/* original tty mode */
-static struct termio	newtermio;	/* raw/noecho tty mode */
+static struct termios	oldtermio;	/* original tty mode */
+static struct termios	newtermio;	/* raw/noecho tty mode */
 #endif
 
 #if BSD || UNIX7 || MINIX
@@ -133,7 +138,7 @@ initscr()
 
 	/* change the terminal mode to raw/noecho */
 #if UNIXV
-	ioctl(2, TCGETA, &oldtermio);
+	tcgetattr(2, &oldtermio);
 #endif
 
 #if BSD || UNIX7 || MINIX
@@ -170,7 +175,7 @@ suspend_curses()
 
 	/* change the terminal mode back the way it was */
 #if UNIXV
-	ioctl(2, TCSETAW, &oldtermio);
+	tcsetattr(2, TCSADRAIN, &oldtermio);
 #endif
 #if BSD || UNIX7 || MINIX
 	ioctl(2, TIOCSETP, &oldsgttyb);
@@ -190,7 +195,7 @@ resume_curses(quietly)
 {	
 	/* change the terminal mode to raw/noecho */
 #if UNIXV
-	ospeed = (oldtermio.c_cflag & CBAUD);
+	ospeed = cfgetospeed(&oldtermio);
 	ERASEKEY = oldtermio.c_cc[VERASE];
 	newtermio = oldtermio;
 	newtermio.c_iflag &= (IXON|IXOFF|IXANY|ISTRIP|IGNBRK);
@@ -199,7 +204,7 @@ resume_curses(quietly)
 	newtermio.c_cc[VINTR] = ctrl('C'); /* always use ^C for interrupts */
 	newtermio.c_cc[VEOF] = 1;	/* minimum # characters to read */
 	newtermio.c_cc[VEOL] = 2;	/* allow at least 0.2 seconds */
-	ioctl(2, TCSETAW, &newtermio);
+	tcsetattr(2, TCSADRAIN, &newtermio);
 #endif
 #if BSD || UNIX7 || MINIX
 	struct tchars	tbuf;
