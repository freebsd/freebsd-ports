--- src/vas4/vas_io.c	2007-07-26 03:14:00.000000000 +0200
+++ src/vas4/vas_io.c	2007-12-28 11:30:45.000000000 +0100
@@ -41,6 +41,8 @@
 #include <stdio.h>
 #include <fcntl.h>
 
+#define HAVE_XOPEN
+
 #if defined(HAVE_XOPEN)
 #  include <termios.h>
 
@@ -93,6 +95,8 @@
 
 	/* Setup VAS line */
 
+#ifndef HAVE_XOPEN
+
 #ifdef HAVE_TERMIO_H
 
 	vtty.c_cflag = BAUD | CS8;      /* Character size = 8 bits */
@@ -137,7 +141,7 @@
 #  endif /* HAVE_SGTTY_H */
 #endif /* HAVE_TERMIO_H */
 
-#ifdef HAVE_XOPEN
+#else /* HAVE_XOPEN */
 	vtty.c_cflag = BAUD | CS8;      /* Character size = 8 bits */
 	vtty.c_cflag &= ~CSTOPB;         /* One stop bit */
 	vtty.c_cflag |= CREAD;           /* Enable the reader */
@@ -149,7 +153,7 @@
 	vtty.c_iflag |= IGNBRK|IGNPAR;
 
 	vtty.c_oflag &= ~(OPOST|ONLCR|OCRNL);    /* Turn off all post-processing */
-	vtty.c_oflag |= TAB3;		/* output tab expansion ON */
+	vtty.c_oflag |= OXTABS;		/* output tab expansion ON */
 	vtty.c_cc[VMIN] = 1;
 	vtty.c_cc[VTIME] = 0;
 
@@ -167,7 +171,7 @@
 		perror(VAS_PORT);
 		exit(2);
 	}
-#endif
+#endif /* !HAVE_XOPEN */
 }
 
 /*
