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
 
@@ -137,6 +139,19 @@
   ttyp = -1;
   if (useTerminal)
     {
+#ifdef FREEBSD
+      int tty_m, tty_s;
+      if (openpty(&tty_m, &tty_s, tty_dev_name, NULL, NULL) == 0)
+        {
+          if (verbose)
+            printf("%s: wire connection on %s\n", progname, tty_dev_name);
+          wire_fd = tty_m;
+          ttyp = tty_s;
+          wire_name = strdup(tty_dev_name);
+        }
+      else
+        perror("openpty");
+#else  /* FREEBSD */
 #ifdef IRIX
       if ((p = _getpty(&wire_fd, O_RDWR | O_EXCL | O_NDELAY, 0666, 0)) == NULL)
         {
@@ -234,11 +249,12 @@
 #endif /* LINUX */
 #endif /* SOLARIS */
 #endif /* IRIX */
+#endif /* FREEBSD */
     }
 
   if (ttyp >= 0)
     {
-#if defined(SUNOS) || defined(HPUX)
+#if defined(SUNOS) || defined(HPUX) || defined (CSRG_BASED)
       if (tcgetattr(ttyp, &ttybuf) < 0)
 #else
       if (ioctl(ttyp, TCGETS, (char *)&ttybuf) < 0)
@@ -263,7 +279,7 @@
 
   if (ttyp >= 0)
     {
-#if defined(SUNOS) || defined (HPUX)
+#if defined(SUNOS) || defined (HPUX) || defined(CSRG_BASED)
       if (tcsetattr(ttyp, TCSANOW, &ttybuf) < 0)
 #else
       if (ioctl(ttyp, TCSETS, (char *)&ttybuf) < 0)
@@ -291,7 +307,7 @@
 
   if (ir_fd >= 0)
     {
-#if defined(SUNOS) || defined (HPUX)
+#if defined(SUNOS) || defined (HPUX) || defined (CSRG_BASED)
       if (tcgetattr(ir_fd, &ttybuf) < 0)
 #else
       if (ioctl(ir_fd, TCGETS, (char *)&ttybuf) < 0)
@@ -315,7 +331,7 @@
 
   if (ir_fd >= 0)
     {
-#if defined(SUNOS) || defined(HPUX)
+#if defined(SUNOS) || defined(HPUX) || defined (CSRG_BASED)
       if (tcsetattr(ir_fd, TCSANOW, &ttybuf) < 0)
 #else
       if (ioctl(ir_fd, TCSETS, (char *)&ttybuf) < 0)
@@ -344,7 +360,7 @@
 
   if (ir_fd >= 0)
     {
-#if defined(SUNOS) || defined (HPUX)
+#if defined(SUNOS) || defined (HPUX) || defined (CSRG_BASED)
       if (tcgetattr(ir_fd, &ttybuf) < 0)
 #else
       if (ioctl(ir_fd, TCGETS, (char *)&ttybuf) < 0)
@@ -358,6 +374,10 @@
         }
     }
 
+#if defined(CSRG_BASED)
+  cfsetspeed(&ttybuf, baud);
+#else
+
   ttybuf.c_cflag &= ~CBAUD;
 
   baud &= 0x7;
@@ -404,9 +424,11 @@
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
@@ -422,7 +444,7 @@
 
   if (ttyp >= 0)
     {
-#if defined(SUNOS) || defined(HPUX)
+#if defined(SUNOS) || defined(HPUX) || defined (CSRG_BASED)
       if (tcgetattr(ttyp, &ttybuf) < 0)
 #else
       if (ioctl(ttyp, TCGETS, (char *)&ttybuf) < 0)
@@ -437,6 +459,9 @@
         }
     }
 
+#if defined(CSRG_BASED)
+  cfsetspeed(&ttybuf, baud);
+#else
   ttybuf.c_cflag &= ~CBAUD;
 
   baud &= 0x7;
@@ -482,10 +507,11 @@
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
