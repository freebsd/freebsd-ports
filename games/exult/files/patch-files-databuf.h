--- files/databuf.h.orig	Sun Aug 31 21:32:25 2003
+++ files/databuf.h	Wed Mar 31 13:37:08 2004
@@ -21,7 +21,9 @@
 #  include <cstdio>
 #  include <cstring>
 #endif
+#if defined(__GNUC__) && __GNUC__ >= 3
 #include <cassert>
+#endif
 #include <fstream>
 #include <iomanip>
 #include "U7file.h"
