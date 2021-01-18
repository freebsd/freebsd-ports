--- threader.c.orig	2021-01-14 22:06:20 UTC
+++ threader.c
@@ -22,6 +22,9 @@
  *
  * This example works with Win32 as with OS/2 or Posix threads.
  */
+
+#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"
+
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
