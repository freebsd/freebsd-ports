--- va_list.c.orig	2015-08-04 22:06:53 UTC
+++ va_list.c
@@ -0,0 +1,6 @@
+#ifdef __FreeBSD__
+#undef __GNUC__
+#undef __GNUC_MINOR__
+#include <sys/types.h>
+void foo(__va_list);
+#endif
