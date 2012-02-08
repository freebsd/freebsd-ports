Index: hack/hack.tty.c
@@ -53,6 +53,7 @@
  */
 #ifdef BSD
 #define	V7
+#elif POSIX
 #else
 #define USG
 #endif /* BSD */
@@ -82,6 +83,21 @@
 #define GTTY(x)		(ioctl(0, TCGETA, x))
 #define STTY(x)		(ioctl(0, TCSETA, x))	/* TCSETAF? TCSETAW? */
 
+#elif POSIX
+#include <termios.h>
+#define termstruct	termios
+#define kill_sym	c_cc[VKILL]
+#define erase_sym	c_cc[VERASE]
+#define EXTABS		OXTABS
+#define tabflgs		c_oflag
+#define echoflgs	c_lflag
+#define cbrkflgs	c_lflag
+#define CBRKMASK	ICANON
+#define CBRKON		! /* reverse condition */
+#define OSPEED(x)	cfgetospeed(x)
+#define GTTY(x)		tcgetattr(fileno(stdin),x)
+#define STTY(x)		tcsetattr(fileno(stdin),TCSANOW,x)	/* TCSETAF? TCSETAW? */
+
 #else	/* V7 */
 
 #include	<sgtty.h>
@@ -169,6 +185,10 @@
 		/* be satisfied with one character; no timeout */
 		curttyb.c_cc[VMIN] = 1;		/* was VEOF */
 		curttyb.c_cc[VTIME] = 0;	/* was VEOL */
+#elif POSIX
+		/* be satisfied with one character; no timeout */
+		curttyb.c_cc[VMIN] = 1;		/* was VEOF */
+		curttyb.c_cc[VTIME] = 0;	/* was VEOL */
 #endif /* USG */
 		change++;
 	}
