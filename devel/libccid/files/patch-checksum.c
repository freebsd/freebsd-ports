--- src/openct/checksum.c.orig	Wed Apr 20 15:16:48 2005
+++ src/openct/checksum.c	Wed Apr 20 15:17:04 2005
@@ -5,7 +5,9 @@
  * For licensing, see the file LICENCE
  */
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <unistd.h>
 
 #define min( a, b )   ( ( ( a ) < ( b ) ) ? ( a ) : ( b ) )
