--- files/databuf.h.orig	Thu May 23 07:24:04 2002
+++ files/databuf.h	Sat Aug 16 17:54:30 2003
@@ -24,6 +24,9 @@
 #ifdef MACOS
 #  include <cassert>
 #endif
+#if defined(__GNUC__) && __GNUC__ >= 3
+#  include <cassert>
+#endif
 #include <fstream>
 #include <iomanip>
 #include "U7file.h"
