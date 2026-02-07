--- depack.h.orig	1995-03-03 14:25:04 UTC
+++ depack.h
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
