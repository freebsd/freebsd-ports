$FreeBSD$

--- larn/io.c	24 Jan 2004 21:00:14 -0000	1.3
+++ larn/io.c	21 Jun 2004 02:28:34 -0000	1.4
@@ -25,7 +25,7 @@
  *	FILE INPUT ROUTINES
  *
  *	long lgetc()				read one character from input buffer
- *	long lrint()				read one integer from input buffer
+ *	long lrint_x()				read one integer from input buffer
  *	lrfill(address,number)		put input bytes into a buffer
  *	char *lgetw()				get a whitespace ended word from input
  *	char *lgetl()				get a \n or EOF ended line from input
@@ -343,7 +343,7 @@
     }
 
 /*
- *	long lrint()			Read one integer from input buffer
+ *	long lrint_x()			Read one integer from input buffer
  *
  *		+---------+---------+---------+---------+
  *		|	high  |			|		  |	  low	|
@@ -355,7 +355,7 @@
  *	The save order is low order first, to high order (4 bytes total)
  *	Returns the int read
  */
-long lrint()
+long lrint_x()
 	{
 	unsigned long i;
 	i  = 255 & lgetc();				i |= (255 & lgetc()) << 8;
