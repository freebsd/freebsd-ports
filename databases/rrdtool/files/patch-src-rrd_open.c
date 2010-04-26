--- src/rrd_open.c.orig	2010-03-23 00:05:55.000000000 +0800
+++ src/rrd_open.c	2010-04-26 03:46:23.000000000 +0800
@@ -555,9 +555,6 @@
     int       ret;
 
 #ifdef HAVE_MMAP
-    ret = msync(rrd_simple_file->file_start, rrd_file->file_len, MS_ASYNC);
-    if (ret != 0)
-        rrd_set_error("msync rrd_file: %s", rrd_strerror(errno));
     ret = munmap(rrd_simple_file->file_start, rrd_file->file_len);
     if (ret != 0)
         rrd_set_error("munmap rrd_file: %s", rrd_strerror(errno));
