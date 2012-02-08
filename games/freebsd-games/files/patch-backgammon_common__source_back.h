Index: backgammon/common_source/back.h
@@ -33,7 +33,13 @@
  *	@(#)back.h	8.1 (Berkeley) 5/31/93
  */
 
-#include <sgtty.h>
+#include <termios.h>
+
+#define sg_erase c_cc[2]
+#define sg_kill c_cc[3]
+
+#define gtty(_a,_b) tcgetattr(_a,_b)
+#define stty(_a,_b) tcsetattr(_a,TCSANOW,_b)
 
 #define rnum(r)	(random()%r)
 #define D0	dice[0]
@@ -114,7 +120,7 @@
 extern const char *const *Colorptr;	/* color of current player, capitalized */
 extern int	colen;		/* length of color of current player */
 
-extern struct sgttyb	tty;	/* tty information buffer */
+extern struct termios	tty;	/* tty information buffer */
 extern int		old;	/* original tty status */
 extern int		noech;	/* original tty status without echo */
 extern int		raw;	/* raw tty status, no echo */
