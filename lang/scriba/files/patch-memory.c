--- memory.c.orig	Mon Apr 22 01:40:39 2002
+++ memory.c	Tue Mar  1 22:11:42 2005
@@ -19,7 +19,11 @@
 
 TO_HEADER:
 
-typedef unsigned char BYTE, *PBYTE;
+#ifndef BYTE_TYPE_ALREADY_DEFINED
+typedef unsigned char BYTE;
+#endif
+
+typedef unsigned char *PBYTE;
 
 typedef struct _FixSizeMemoryObject {
 
