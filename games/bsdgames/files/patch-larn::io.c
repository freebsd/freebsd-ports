--- larn/io.c.orig	Thu May  9 06:39:10 2002
+++ larn/io.c	Sun Apr 16 20:40:41 2006
@@ -24,7 +24,7 @@
  *	FILE INPUT ROUTINES
  *
  *	long lgetc()				read one character from input buffer
- *	long lrint()				read one integer from input buffer
+ *	long lrint_x()				read one integer from input buffer
  *	lrfill(address,number)		put input bytes into a buffer
  *	char *lgetw()				get a whitespace ended word from input
  *	char *lgetl()				get a \n or EOF ended line from input
@@ -75,6 +75,9 @@
 #define CBREAK RAW		/* V7 has no CBREAK */
 #endif
 
+#define stty(_a,_b) ioctl(_a,TIOCSETP,_b)
+#define gtty(_a,_b) ioctl(_a,TIOCGETP,_b)
+
 #define doraw(_a) (_a.sg_flags |= CBREAK,_a.sg_flags &= ~ECHO)
 #define unraw(_a) (_a.sg_flags &= ~CBREAK,_a.sg_flags |= ECHO)
 #include <sgtty.h>
@@ -345,7 +348,7 @@
     }
 
 /*
- *	long lrint()			Read one integer from input buffer
+ *	long lrint_x()			Read one integer from input buffer
  *
  *		+---------+---------+---------+---------+
  *		|	high  |			|		  |	  low	|
@@ -357,7 +360,7 @@
  *	The save order is low order first, to high order (4 bytes total)
  *	Returns the int read
  */
-long lrint()
+long lrint_x()
 	{
 	unsigned long i;
 	i  = 255 & lgetc();				i |= (255 & lgetc()) << 8;
