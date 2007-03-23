Index: hack/hack.ioctl.c
@@ -13,6 +13,9 @@
 #ifdef BSD
 #include	<sgtty.h>
 struct ltchars ltchars, ltchars0;
+#elif POSIX
+#include 	<termios.h>
+struct termios termio;
 #else
 #include	<termio.h>	/* also includes part of <sgtty.h> */
 struct termio termio;
@@ -22,6 +25,8 @@
 #ifdef BSD
 	(void) ioctl(fileno(stdin), (int) TIOCGLTC, (char *) &ltchars);
 	(void) ioctl(fileno(stdin), (int) TIOCSLTC, (char *) &ltchars0);
+#elif POSIX
+	tcgetattr(fileno(stdin), &termio);
 #else
 	(void) ioctl(fileno(stdin), (int) TCGETA, &termio);
 #endif /* BSD */
@@ -30,6 +35,8 @@
 setioctls() {
 #ifdef BSD
 	(void) ioctl(fileno(stdin), (int) TIOCSLTC, (char *) &ltchars);
+#elif POSIX
+	tcsetattr(fileno(stdin), TCSANOW, &termio);
 #else
 	(void) ioctl(fileno(stdin), (int) TCSETA, &termio);
 #endif /* BSD */
