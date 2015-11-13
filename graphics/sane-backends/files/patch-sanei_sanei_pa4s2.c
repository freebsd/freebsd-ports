--- sanei/sanei_pa4s2.c.orig	2015-09-20 11:55:39 UTC
+++ sanei/sanei_pa4s2.c
@@ -112,6 +112,12 @@ inb (u_long port)
 
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
