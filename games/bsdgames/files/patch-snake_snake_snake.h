Index: snake/snake/snake.h
@@ -38,10 +38,13 @@
 # include <stdio.h>
 # include <assert.h>
 # include <sys/types.h>
-# include <sgtty.h>
+# include <termios.h>
 # include <signal.h>
 # include <math.h>
 
+#define gtty(_a,_b) tcgetattr(_a,_b)
+#define stty(_a,_b) tcsetattr(_a,TCSANOW,_b)
+
 #define ESC	'\033'
 
 struct tbuffer {
@@ -72,7 +75,7 @@
 	int col, line;
 };
 struct point cursor;
-struct sgttyb orig, new;
+struct termios orig, new;
 #ifdef TIOCLGET
 struct ltchars olttyc, nlttyc;
 #endif
