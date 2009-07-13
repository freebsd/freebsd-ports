--- administrator/source/linux/MInstanceInfo.cc.orig	2009-07-08 11:56:19.000000000 +0200
+++ administrator/source/linux/MInstanceInfo.cc	2009-07-08 11:58:17.000000000 +0200
@@ -1124,7 +1124,7 @@
       char *buffer= (char*)g_malloc(diff+1);
       int fd= open(path.c_str(), O_RDONLY);
 
-      lseek64(fd, _log_file_pos, SEEK_SET);
+      lseek(fd, _log_file_pos, SEEK_SET);
       if ((len= read(fd, buffer, diff)) < 0)
       {
         close(fd);
