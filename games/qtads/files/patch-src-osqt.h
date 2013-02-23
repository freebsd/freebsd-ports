--- src/osqt.h.orig	2013-02-05 12:40:00.000000000 +0100
+++ src/osqt.h	2013-02-05 12:40:26.000000000 +0100
@@ -35,6 +35,9 @@
     #endif
 #endif
 
+/* FreeBSD doesn't have ulong defined. */
+#undef OS_ULONG_DEFINED
+
 #define OSNOUI_OMIT_OS_FPRINTZ
 #define OSNOUI_OMIT_OS_FPRINT
 #define OSNOUI_OMIT_OS_CVT_URL_DIR
