--- pro_incl.h.orig	Mon Nov 22 19:20:35 2004
+++ pro_incl.h	Sat Feb 12 22:17:11 2005
@@ -38,6 +38,18 @@
 #ifdef HAVE_ELF_H
 #include <elf.h>
 #endif
+#ifdef __SGI_FAST_LIBELF
+#include <libelf_sgi.h>
+#else
+#ifdef HAVE_LIBELF_H
+#include <libelf.h>
+#else
+#ifdef HAVE_LIBELF_LIBELF_H
+#include <libelf/libelf.h>
+#endif
+#endif
+#endif /* !defined(__SGI_FAST_LIBELF) */
+
 
 /* The target address is given: the place in the source integer
    is to be determined.
