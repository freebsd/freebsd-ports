--- screen.c	Wed May 21 04:38:05 1997
+++ screen.c	Mon Jun  4 10:36:47 2007
@@ -127,7 +127,7 @@
 #define  MIN_HEIGHT	24
 
 #ifdef TERMIO
-# include <termio.h>
+# include <termios.h>
 #else
 # include <sgtty.h>
 #endif
@@ -177,9 +177,9 @@
 	int sw;
 {
 	static int	firsttime = 1;
-	struct termio *s;
-	static struct termio save_term;
-	static struct termio raw_term;
+	struct termios *s;
+	static struct termios save_term;
+	static struct termios raw_term;
 
 	if (sw) {
 		s = &raw_term;
