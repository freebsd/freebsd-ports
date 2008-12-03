--- pro_incl.h.orig	2008-06-16 10:06:57.000000000 -0500
+++ pro_incl.h	2008-07-05 10:15:46.000000000 -0500
@@ -43,6 +43,14 @@
    type defined (a required type). */
 #include <libelf.h>
 #endif
+#ifdef HAVE_LIBELF_H
+#include <libelf.h>
+#else
+#ifdef HAVE_LIBELF_LIBELF_H
+#include <libelf/libelf.h>
+#endif
+#endif
+
 
 #if defined(sun)
 #include <sys/elf_SPARC.h>
