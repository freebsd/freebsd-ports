--- gio/gresource-tool.c.orig	2025-04-03 14:38:51 UTC
+++ gio/gresource-tool.c
@@ -31,8 +31,10 @@
 #include <locale.h>
 
 #ifdef HAVE_LIBELF
-#include <libelf.h>
-#include <gelf.h>
+#include </usr/include/libelf.h>
+// fool libelf from ports to not include its libelf.h
+#define _LIBELF_H 1
+#include </usr/include/gelf.h>
 #endif
 
 #ifdef HAVE_MMAP
