--- chmlib/chm_lib.c.orig	Tue Nov  8 16:18:06 2005
+++ chmlib/chm_lib.c	Tue Nov  8 16:20:05 2005
@@ -171,7 +171,7 @@
 
 /* x86-64 */
 /* Note that these may be appropriate for other 64-bit machines. */
-#elif __x86_64__
+#elif __x86_64__ || __ia64__ || __alpha__ || __sparc64__
 typedef unsigned char           UChar;
 typedef short                   Int16;
 typedef unsigned short          UInt16;
