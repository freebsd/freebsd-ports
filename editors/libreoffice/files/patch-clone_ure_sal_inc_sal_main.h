--- clone/ure/sal/inc/sal/main.h.orig	2011-05-19 11:22:58.000000000 +0000
+++ clone/ure/sal/inc/sal/main.h	2011-08-24 21:15:27.305581455 +0000
@@ -30,8 +30,11 @@
 #define _SAL_MAIN_H_
 
 #include <sal/types.h>
-#if defined(AIX)
+#if defined(AIX) || defined(FREEBSD)
 #   include <unistd.h>
+//*Hurl*, *Puke*, temp fix only, will
+//cause other weirdness eventually
+#  define BROKEN_SHUTDOWN
 #endif
 
 #ifdef __cplusplus
@@ -41,6 +44,16 @@ extern "C" {
 void SAL_CALL sal_detail_initialize(int argc, char ** argv);
 void SAL_CALL sal_detail_deinitialize();
 
+/**
+ * TODO(gliaskos): Use this hack for now but we should remove it eventually.
+ * ctx: http://www.mail-archive.com/libreoffice@lists.freedesktop.org/msg04427.html 
+ */
+#ifdef BROKEN_SHUTDOWN
+#  define MAINRET(x) _exit(x)
+#else
+#  define MAINRET(x) return x
+#endif
+
 #define SAL_MAIN_WITH_ARGS_IMPL \
 int SAL_CALL main(int argc, char ** argv) \
 { \
@@ -48,7 +61,7 @@ int SAL_CALL main(int argc, char ** argv
     sal_detail_initialize(argc, argv);   \
     ret = sal_main_with_args(argc, argv); \
     sal_detail_deinitialize(); \
-    return ret; \
+    MAINRET(ret); \
 }
 
 #define SAL_MAIN_IMPL \
@@ -58,7 +71,7 @@ int SAL_CALL main(int argc, char ** argv
     sal_detail_initialize(argc, argv); \
     ret = sal_main(); \
     sal_detail_deinitialize(); \
-    return ret; \
+    MAINRET(ret); \
 }
 
 /* Definition macros for CRT entries */
