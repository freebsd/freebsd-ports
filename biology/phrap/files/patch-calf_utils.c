--- ./calf_utils.c.orig	2008-11-04 23:21:50.000000000 +0100
+++ ./calf_utils.c	2014-08-02 12:39:30.000000000 +0200
@@ -28,6 +28,8 @@
 
 extern void *malloc(), *realloc();
 
+void read_type_3(File_stat *, int);
+
 append_file_stat(file_name)
      char *file_name;
 {
@@ -110,6 +112,7 @@
   get_record_header(file_stat);
 }
 
+void
 read_type_3(file_stat, new_rec_flag)
      File_stat *file_stat;
      int new_rec_flag;
