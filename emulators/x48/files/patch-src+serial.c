--- src/serial.c.orig	Fri Jun 24 14:48:29 2005
+++ src/serial.c	Mon Aug 28 20:04:25 2006
@@ -134,7 +134,19 @@
   ttyp = -1;
   if (useTerminal)
     {
-#if defined(IRIX)
+#if defined(CSRG_BASED)
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
+#elif defined(IRIX)
       if ((p = _getpty(&wire_fd, O_RDWR | O_EXCL | O_NDELAY, 0666, 0)) == NULL)
         {
           wire_fd = -1;
@@ -414,6 +426,8 @@
         fprintf(stderr, "%s: can\'t set baud rate, using 9600\n", progname);
       ttybuf.c_cflag |= B9600;
     }
+#elif defined(CSRG_BASED)
+  cfsetspeed(&ttybuf, baud);
 #else
   ttybuf.c_cflag &= ~CBAUD;
 
@@ -495,6 +509,8 @@
     }
 
 #if defined(__APPLE__)
+#elif defined(CSRG_BASED)
+  cfsetspeed(&ttybuf, baud);
 #else
   ttybuf.c_cflag &= ~CBAUD;
 
