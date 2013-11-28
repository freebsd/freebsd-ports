--- ztypes.h.orig	Sun May  9 16:02:32 1999
+++ ztypes.h	Sun May  9 16:02:52 1999
@@ -19,6 +19,8 @@
 #include <malloc.h>
 #endif /* MSDOS */
 
+#include <machine/endian.h>
+
 /* Try the endianness auto-detect. */
 
 #ifdef AUTO_END_MODE
