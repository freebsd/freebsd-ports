--- depack.h.orig	Sat May 22 21:55:32 1999
+++ depack.h	Sat May 22 21:56:18 1999
@@ -4,8 +4,10 @@
  * see accompanying file README for distribution information
  */
 
+#include <sys/types.h>
+
 typedef unsigned char ubyte;
-typedef unsigned long ulong;
+#define ulong uint
 
 extern ulong depackedlen(ubyte *packed, ulong plen);
 extern void ppdepack(ubyte *packed, ubyte *depacked, ulong plen, ulong unplen);
