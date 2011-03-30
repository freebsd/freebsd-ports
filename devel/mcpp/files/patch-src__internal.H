--- ./src/internal.H.orig	2008-08-27 15:01:16.000000000 +0200
+++ ./src/internal.H	2011-03-30 19:57:37.000000000 +0200
@@ -390,6 +390,8 @@
 extern char     identifier[];       /* Lastly scanned name          */
 extern IFINFO   ifstack[];          /* Information of #if nesting   */
 extern char     work_buf[];
+extern FILEINFO * sh_file;
+extern int      sh_line;
         /* Temporary buffer for directive line and macro expansion  */
 
 /* main.c   */
@@ -557,6 +559,6 @@
 #endif
 #endif
 
-#if HOST_HAVE_STPCPY
+#if HOST_HAVE_STPCPY && !defined(stpcpy)
 extern char *   stpcpy( char * dest, const char * src);
 #endif
