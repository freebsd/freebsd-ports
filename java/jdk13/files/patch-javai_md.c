$FreeBSD$

--- ../src/solaris/javavm/runtime/javai_md.c	24 Jul 2003 07:06:56 -0000	1.7
+++ ../src/solaris/javavm/runtime/javai_md.c	15 Jan 2004 07:37:23 -0000
@@ -137,7 +137,7 @@
 #ifdef __linux__
 #define DEFAULT_LD_LIBRARY_PATH "/usr/lib:/lib" /* See ld.so(8) */
 #else
-#define DEFAULT_LD_LIBRARY_PATH "/usr/lib" /* See ld.so.1(1) */
+#define DEFAULT_LD_LIBRARY_PATH "/usr/lib:%%LOCALBASE%%/lib" /* See ld.so.1(1) */
 #endif
     {
 	/* Get the user setting of LD_LIBRARY_PATH */
