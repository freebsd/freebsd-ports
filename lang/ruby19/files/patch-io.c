--- io.c.orig	2009-01-28 12:20:46.000000000 +0300
+++ io.c	2009-02-09 19:18:58.000000000 +0300
@@ -6685,7 +6685,7 @@
 }
 
 static int
-io_cntl(int fd, int cmd, long narg, int io_p)
+io_cntl(int fd, unsigned long cmd, long narg, int io_p)
 {
     int retval;
 
@@ -6707,7 +6707,7 @@
 static VALUE
 rb_io_ctl(VALUE io, VALUE req, VALUE arg, int io_p)
 {
-    int cmd = NUM2ULONG(req);
+    unsigned long cmd = NUM2ULONG(req);
     rb_io_t *fptr;
     long len = 0;
     long narg = 0;
