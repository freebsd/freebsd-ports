--- sanei/sanei_pa4s2.c.orig	2010-04-05 22:18:06.000000000 +0900
+++ sanei/sanei_pa4s2.c	2010-05-10 22:07:48.000000000 +0900
@@ -109,6 +109,12 @@
 
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
