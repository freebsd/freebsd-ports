--- src/serial.c.orig	Tue Sep  7 10:41:48 1999
+++ src/serial.c	Sat Jun 28 21:27:06 2003
@@ -69,7 +69,7 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/time.h>
-#if defined(LINUX) || defined(HPUX)
+#if defined(LINUX) || defined(HPUX) || defined(CSRG_BASED)
 #include <sys/ioctl.h>
 #endif
 #include <unistd.h>
@@ -77,6 +77,8 @@
 #ifdef SOLARIS
 #include <sys/stream.h>
 #include <sys/stropts.h>
+#endif
+#if defined(SOLARIS) || defined(CSRG_BASED)
 #include <sys/termios.h>
 #endif
 
@@ -238,7 +240,7 @@
 
   if (ttyp >= 0)
     {
-#if defined(SUNOS) || defined(HPUX)
+#if defined(SUNOS) || defined(HPUX) || defined (CSRG_BASED)
       if (tcgetattr(ttyp, &ttybuf) < 0)
 #else
       if (ioctl(ttyp, TCGETS, (char *)&ttybuf) < 0)
@@ -263,7 +265,7 @@
 
   if (ttyp >= 0)
     {
-#if defined(SUNOS) || defined (HPUX)
+#if defined(SUNOS) || defined (HPUX) || defined(CSRG_BASED)
       if (tcsetattr(ttyp, TCSANOW, &ttybuf) < 0)
 #else
       if (ioctl(ttyp, TCSETS, (char *)&ttybuf) < 0)
@@ -291,7 +293,7 @@
 
   if (ir_fd >= 0)
     {
-#if defined(SUNOS) || defined (HPUX)
+#if defined(SUNOS) || defined (HPUX) || defined (CSRG_BASED)
       if (tcgetattr(ir_fd, &ttybuf) < 0)
 #else
       if (ioctl(ir_fd, TCGETS, (char *)&ttybuf) < 0)
@@ -315,7 +317,7 @@
 
   if (ir_fd >= 0)
     {
-#if defined(SUNOS) || defined(HPUX)
+#if defined(SUNOS) || defined(HPUX) || defined (CSRG_BASED)
       if (tcsetattr(ir_fd, TCSANOW, &ttybuf) < 0)
 #else
       if (ioctl(ir_fd, TCSETS, (char *)&ttybuf) < 0)
@@ -344,7 +346,7 @@
 
   if (ir_fd >= 0)
     {
-#if defined(SUNOS) || defined (HPUX)
+#if defined(SUNOS) || defined (HPUX) || defined (CSRG_BASED)
       if (tcgetattr(ir_fd, &ttybuf) < 0)
 #else
       if (ioctl(ir_fd, TCGETS, (char *)&ttybuf) < 0)
@@ -358,6 +360,10 @@
         }
     }
 
+#if defined(CSRG_BASED)
+  cfsetspeed(&ttybuf, baud);
+#else
+
   ttybuf.c_cflag &= ~CBAUD;
 
   baud &= 0x7;
@@ -404,9 +410,11 @@
       ttybuf.c_cflag |= B9600;
     }
 
+#endif /* CSRG_BASED */
+
   if (ir_fd >= 0)
     {
-#if defined(SUNOS) || defined(HPUX)
+#if defined(SUNOS) || defined(HPUX) || defined (CSRG_BASED)
       if (tcsetattr(ir_fd, TCSANOW, &ttybuf) < 0)
 #else
       if (ioctl(ir_fd, TCSETS, (char *)&ttybuf) < 0)
@@ -422,7 +430,7 @@
 
   if (ttyp >= 0)
     {
-#if defined(SUNOS) || defined(HPUX)
+#if defined(SUNOS) || defined(HPUX) || defined (CSRG_BASED)
       if (tcgetattr(ttyp, &ttybuf) < 0)
 #else
       if (ioctl(ttyp, TCGETS, (char *)&ttybuf) < 0)
@@ -437,6 +445,9 @@
         }
     }
 
+#if defined(CSRG_BASED)
+  cfsetspeed(&ttybuf, baud);
+#else
   ttybuf.c_cflag &= ~CBAUD;
 
   baud &= 0x7;
@@ -482,10 +493,11 @@
         fprintf(stderr, "%s: can\'t set baud rate, using 9600\n", progname);
       ttybuf.c_cflag |= B9600;
     }
+#endif
 
   if (ttyp >= 0)
     {
-#if defined(SUNOS) || defined(HPUX)
+#if defined(SUNOS) || defined(HPUX) || defined (CSRG_BASED)
       if (tcsetattr(ttyp, TCSANOW, &ttybuf) < 0)
 #else
       if (ioctl(ttyp, TCSETS, (char *)&ttybuf) < 0)
