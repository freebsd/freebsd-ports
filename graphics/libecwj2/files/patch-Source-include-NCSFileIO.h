--- Source/include/NCSFileIO.h.orig	2009-04-05 21:25:23.000000000 +0400
+++ Source/include/NCSFileIO.h	2009-04-05 21:25:47.000000000 +0400
@@ -108,7 +108,7 @@
 #define NCS_FILE_SEP "/"
 #define NCS_FILE_SEP_T NCS_T("/")
 
-#elif defined SOLARIS || defined HPUX || defined LINUX
+#elif defined SOLARIS || defined HPUX || defined LINUX || defined FREEBSD
 
 #include <sys/types.h>
 #include <sys/stat.h>
