--- Modules/_decimal/libmpdec/io.c.orig	2013-02-02 13:00:09.687048586 +0000
+++ Modules/_decimal/libmpdec/io.c	2013-02-02 13:29:21.722048769 +0000
@@ -25,6 +25,13 @@
  * SUCH DAMAGE.
  */
 
+/* Work around bug in FreeBSD 9.1-RELEASE; fixed in r243331 */
+
+#ifndef __GNUC_STDC_INLINE__
+#define __GNUC_STDC_INLINE__ 0
+#endif
+
+
 #include "mpdecimal.h"
 #include <stdio.h>
 #include <stdlib.h>
