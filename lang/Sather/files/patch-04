--- System/Platforms/unix/header.h.orig	Sat Sep 11 23:33:03 1999
+++ System/Platforms/unix/header.h	Wed Feb  2 20:57:51 2000
@@ -15,7 +15,11 @@
 #define _HEADER_H_
 
 #ifndef ZONES
+#  ifdef __FreeBSD__
+#  include <gc.h>
+#  else
 #  include <gc/gc.h>
+#  endif
 #endif
 
 #include "../../Common/c_header.h"
