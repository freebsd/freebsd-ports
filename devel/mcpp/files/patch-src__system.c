--- ./src/system.c.orig	2008-11-26 10:53:51.000000000 +0100
+++ ./src/system.c	2011-03-30 19:57:37.000000000 +0200
@@ -3858,6 +3858,9 @@
 }
 #endif
 
+FILEINFO*       sh_file;
+int             sh_line;
+
 void    sharp(
     FILEINFO *  sharp_file,
     int         flag        /* Flag to append to the line for GCC   */
@@ -3868,8 +3871,6 @@
  * else (i.e. 'sharp_file' is NULL) 'infile'.
  */
 {
-    static FILEINFO *   sh_file;
-    static int  sh_line;
     FILEINFO *  file;
     int         line;
 
