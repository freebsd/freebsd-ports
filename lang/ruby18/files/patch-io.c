--- io.c.orig	2008-06-08 22:20:37.000000000 +0400
+++ io.c	2009-02-12 01:10:27.000000000 +0300
@@ -4970,8 +4970,9 @@
 #if !defined(MSDOS) && !defined(__human68k__)
 static int
 io_cntl(fd, cmd, narg, io_p)
-    int fd, cmd, io_p;
+    int fd, io_p;
     long narg;
+    unsigned long cmd;
 {
     int retval;
 
@@ -5001,7 +5002,7 @@
     int io_p;
 {
 #if !defined(MSDOS) && !defined(__human68k__)
-    int cmd = NUM2ULONG(req);
+    unsigned long cmd = NUM2ULONG(req);
     rb_io_t *fptr;
     long len = 0;
     long narg = 0;
