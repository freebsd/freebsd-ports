--- mono/utils/w32handle.c.orig	2017-05-01 16:30:13 UTC
+++ mono/utils/w32handle.c
@@ -51,7 +51,7 @@
 
 #undef DEBUG_REFS
 
-#define SLOT_MAX		(1024 * 16)
+#define SLOT_MAX		(1024 * 32)
 
 /* must be a power of 2 */
 #define HANDLE_PER_SLOT	(256)
