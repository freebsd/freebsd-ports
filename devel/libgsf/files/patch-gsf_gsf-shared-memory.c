--- gsf/gsf-shared-memory.c.orig	Wed Sep 11 23:58:35 2002
+++ gsf/gsf-shared-memory.c	Wed Sep 11 23:58:46 2002
@@ -21,6 +21,7 @@
 #include <gsf-config.h>
 #include <gsf/gsf-shared-memory.h>
 #include <gsf/gsf-impl-utils.h>
+#include <sys/types.h>
 
 #ifdef HAVE_MMAP
 #include <sys/mman.h>
