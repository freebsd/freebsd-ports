Index: larn/io.c
@@ -24,7 +24,7 @@
  *	FILE INPUT ROUTINES
  *
  *	long lgetc()				read one character from input buffer
- *	long lrint()				read one integer from input buffer
+ *	long lrint_x()				read one integer from input buffer
  *	lrfill(address,number)		put input bytes into a buffer
  *	char *lgetw()				get a whitespace ended word from input
  *	char *lgetl()				get a \n or EOF ended line from input
@@ -69,6 +69,17 @@
     _a.c_cc[VMIN]=1;_a.c_cc[VTIME]=1;_a.c_lflag &= ~(ICANON|ECHO|ECHOE|ECHOK|ECHONL)
 #define unraw(_a) _a.c_cc[VMIN]=saveeof;_a.c_cc[VTIME]=saveeol;_a.c_lflag |= ICANON|ECHO|ECHOE|ECHOK|ECHONL
 
+#elif POSIX
+#include <termios.h>
+#define sgttyb termios
+#define gtty(_a,_b) tcgetattr(_a,_b)
+#define stty(_a,_b) tcsetattr(_a,TCSANOW,_b)
+static int rawflg = 0;
+static char saveeof,saveeol;
+#define doraw(_a) if(!rawflg){++rawflg;saveeof=_a.c_cc[VMIN];saveeol=_a.c_cc[VTIME];}\
+    _a.c_cc[VMIN]=1;_a.c_cc[VTIME]=1;_a.c_lflag &= ~(ICANON|ECHO|ECHOE|ECHOK|ECHONL)
+#define unraw(_a) _a.c_cc[VMIN]=saveeof;_a.c_cc[VTIME]=saveeol;_a.c_lflag |= ICANON|ECHO|ECHOE|ECHOK|ECHONL
+
 #else /* not SYSV */
 
 #ifndef BSD
@@ -345,7 +356,7 @@
     }
 
 /*
- *	long lrint()			Read one integer from input buffer
+ *	long lrint_x()			Read one integer from input buffer
  *
  *		+---------+---------+---------+---------+
  *		|	high  |			|		  |	  low	|
@@ -357,7 +368,7 @@
  *	The save order is low order first, to high order (4 bytes total)
  *	Returns the int read
  */
-long lrint()
+long lrint_x()
 	{
 	unsigned long i;
 	i  = 255 & lgetc();				i |= (255 & lgetc()) << 8;
