--- sanei/sanei_pa4s2.c.orig	2024-05-23 05:45:00 UTC
+++ sanei/sanei_pa4s2.c
@@ -74,6 +74,12 @@
 
 #endif /* HAVE_LIBIEEE1284 */
 
+#if defined(__FreeBSD__) && defined(__i386__)
+#define HAVE_IOPERM
+#define ioperm i386_set_ioperm
+#include <machine/sysarch.h>
+#endif
+
 #include "../include/sane/sane.h"
 #include "../include/sane/sanei.h"
 #include "../include/sane/sanei_pa4s2.h"
