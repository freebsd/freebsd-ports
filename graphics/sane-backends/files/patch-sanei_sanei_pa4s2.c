--- sanei/sanei_pa4s2.c.orig	Sun Oct  8 22:58:42 2000
+++ sanei/sanei_pa4s2.c	Wed Feb  7 00:28:27 2001
@@ -89,6 +89,12 @@
 #define IO_SUPPORT_MISSING
 #endif
 
+#if defined(__FreeBSD__) && defined(__i386__)
+#define HAVE_IOPERM
+#define ioperm i386_set_ioperm
+#include <machine/sysarch.h>
+#endif
+
 #include "sane/sane.h"
 #include "sane/sanei.h"
 #include "sane/sanei_pa4s2.h"
