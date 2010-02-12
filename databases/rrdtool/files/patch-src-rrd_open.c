--- ./src/rrd_open.c.orig	2009-12-01 23:21:20.000000000 +0000
+++ ./src/rrd_open.c	2009-12-01 23:22:41.000000000 +0000
@@ -552,9 +552,6 @@
     int       ret;
 
 #ifdef HAVE_MMAP
-    ret = msync(rrd_simple_file->file_start, rrd_file->file_len, MS_ASYNC);
-    if (ret != 0)
-        rrd_set_error("msync rrd_file: %s", rrd_strerror(errno));
     ret = munmap(rrd_simple_file->file_start, rrd_file->file_len);
     if (ret != 0)
         rrd_set_error("munmap rrd_file: %s", rrd_strerror(errno));
