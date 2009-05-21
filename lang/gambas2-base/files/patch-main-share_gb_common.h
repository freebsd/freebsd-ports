--- main/share/gb_common.h	2009-05-20 19:03:15.000000000 -0500
+++ main/share/gb_common.h	2009-05-20 19:10:35.000000000 -0500
@@ -51,6 +51,10 @@
 #define HAVE_GETOPT_LONG 1
 #endif
 
+#if defined(OS_FREEBSD) && (defined(__amd64__) || defined(__ia64__) || defined(__sparc64__))
+#define __WORDSIZE 64
+#endif
+
 #if defined(OS_FREEBSD) || defined(OS_OPENBSD)
 
   /* Get definition for PATH_MAX */
