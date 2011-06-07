--- elf32.c.orig	2011-04-05 06:22:54.000000000 +1000
+++ elf32.c	2011-06-04 06:02:31.313405042 +1000
@@ -19,7 +19,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <string.h>
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <libelf.h>
 #else
 #include <elf.h>
