--- ./elftoc/pieces.c.orig	2011-05-26 03:25:14.000000000 +0200
+++ ./elftoc/pieces.c	2011-06-08 12:16:37.000000000 +0200
@@ -16,6 +16,10 @@
 #include "out.h"
 #include "pieces.h"
 
+#ifdef __FreeBSD__
+typedef uint64_t Elf32_Xword;
+#endif
+
 /* Flags used to insert warnings in the generated source code.
  */
 #define	PW_MISALIGNED	0x0001	/* piece misaligned for original type */
