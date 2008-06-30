--- src/rrd_open.c.orig	2008-06-30 12:52:29.000000000 +0800
+++ src/rrd_open.c	2008-06-30 12:53:14.000000000 +0800
@@ -388,9 +388,6 @@
     int       ret;
 
 #ifdef HAVE_MMAP
-    ret = msync(rrd_file->file_start, rrd_file->file_len, MS_ASYNC);
-    if (ret != 0)
-        rrd_set_error("msync rrd_file: %s", rrd_strerror(errno));
     ret = munmap(rrd_file->file_start, rrd_file->file_len);
     if (ret != 0)
         rrd_set_error("munmap rrd_file: %s", rrd_strerror(errno));
