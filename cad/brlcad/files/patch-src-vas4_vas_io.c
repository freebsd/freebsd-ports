Add the following patch to the files/ directory:

--- src/vas4/vas_io.c	2007-07-26 03:14:00.000000000 +0200
+++ src/vas4/vas_io.c	2007-12-28 11:30:45.000000000 +0100
@@ -41,6 +41,8 @@
 #include <stdio.h>
 #include <fcntl.h>
 
+#define HAVE_XOPEN
+
 #if defined(HAVE_XOPEN)
 #  include <termios.h>
 
@@ -149,7 +151,7 @@
 	vtty.c_iflag |= IGNBRK|IGNPAR;
 
 	vtty.c_oflag &= ~(OPOST|ONLCR|OCRNL);    /* Turn off all post-processing */
-	vtty.c_oflag |= TAB3;		/* output tab expansion ON */
+	vtty.c_oflag |= OXTABS;		/* output tab expansion ON */
 	vtty.c_cc[VMIN] = 1;
 	vtty.c_cc[VTIME] = 0;
 
