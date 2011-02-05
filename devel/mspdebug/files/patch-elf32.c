--- elf32.c.orig	Wed Aug  4 04:08:43 2010
+++ elf32.c	Thu Aug 12 12:51:04 2010
@@ -19,7 +19,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <string.h>
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <libelf.h>
 #else
 #include <elf.h>
