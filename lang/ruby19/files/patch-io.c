--- io.c.orig	2007-12-28 02:17:32.000000000 +0300
+++ io.c	2007-12-28 02:17:58.000000000 +0300
@@ -5324,7 +5324,7 @@
 
 #if !defined(MSDOS) && !defined(__human68k__)
 static int
-io_cntl(int fd, int cmd, long narg, int io_p)
+io_cntl(int fd, unsigned long cmd, long narg, int io_p)
 {
     int retval;
 
@@ -5352,7 +5352,7 @@
 rb_io_ctl(VALUE io, VALUE req, VALUE arg, int io_p)
 {
 #if !defined(MSDOS) && !defined(__human68k__)
-    int cmd = NUM2ULONG(req);
+    unsigned long cmd = NUM2ULONG(req);
     rb_io_t *fptr;
     long len = 0;
     long narg = 0;
