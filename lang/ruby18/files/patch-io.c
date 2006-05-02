--- io.c.orig	Thu Mar  2 22:15:47 2006
+++ io.c	Thu Mar  2 22:16:58 2006
@@ -4682,8 +4682,9 @@
 #if !defined(MSDOS) && !defined(__human68k__)
 static int
 io_cntl(fd, cmd, narg, io_p)
-    int fd, cmd, io_p;
+    int fd, io_p;
     long narg;
+    unsigned long cmd;
 {
     int retval;
 
@@ -4713,7 +4714,7 @@
     int io_p;
 {
 #if !defined(MSDOS) && !defined(__human68k__)
-    int cmd = NUM2ULONG(req);
+    unsigned long cmd = NUM2ULONG(req);
     OpenFile *fptr;
     long len = 0;
     long narg = 0;
