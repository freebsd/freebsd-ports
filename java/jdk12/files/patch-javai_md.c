$FreeBSD$

--- ../../src/bsd/javavm/runtime/javai_md.c	Mon Jan 19 12:37:59 2004
+++ ../../src/bsd/javavm/runtime/javai_md.c	Mon Jan 19 12:32:23 2004
@@ -147,7 +147,7 @@
     }
 
     /* Where to look for native libraries */
-#define DEFAULT_LD_LIBRARY_PATH "/usr/lib" /* See ld.so.1(1) */
+#define DEFAULT_LD_LIBRARY_PATH "/usr/lib:%%LOCALBASE%%/lib" /* See ld.so.1(1) */
     {
 	/* Get the user setting of LD_LIBRARY_PATH */
 	v = getenv("LD_LIBRARY_PATH");
