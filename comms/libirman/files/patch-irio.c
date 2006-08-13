--- irio.c.orig	Mon Mar 29 00:42:41 1999
+++ irio.c	Thu Aug 10 22:44:50 2006
@@ -66,17 +66,11 @@
  *
  */
 
-/*
- * Ignore the things in SUNATTEMPT.  They're not even needed for a Sun.
- */
- 
-
 int ir_open_port(char *filename)
 {
   int parnum = 0;
-#ifdef SUNATTEMPT
+  int clearhand = 0;
   int hand = TIOCM_DTR | TIOCM_RTS;
-#endif
   int baudrate=B9600;
 
   /* get a file descriptor */
@@ -188,13 +182,19 @@
     return -1;
   }
 
-#ifdef SUNATTEMPT
+  /* drop the control lines to cut power to the unit */
+  if (ioctl(portfd, TIOCMSET, &clearhand) < 0) {
+    printf("ioctl error\n");
+    return -1;
+  }
+
+  sleep(2);
+
   /* raise the control lines to power the unit*/
   if (ioctl(portfd, TIOCMSET, &hand) < 0) {
     printf("ioctl error\n");
     return -1;
   }
-#endif
 
   /* wait a little while for everything to settle through */
   ir_usleep(IR_POWER_ON_LATENCY);
