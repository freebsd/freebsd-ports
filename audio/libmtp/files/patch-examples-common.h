--- examples/common.h.orig	Sun Feb 18 22:24:01 2007
+++ examples/common.h	Sun Feb 18 22:17:34 2007
@@ -3,7 +3,7 @@
  * These headers are used by absolutely all sample programs.
  * Special quirks that apply to all samples go here.
  */
-#include <libmtp.h>
+#include <../src/libmtp.h>
 #ifndef _MSC_VER
 #include "config.h"
 #ifdef HAVE_GETOPT_H
