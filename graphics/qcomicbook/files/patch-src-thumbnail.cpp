--- src/thumbnail.cpp.orig	Sat Apr  2 19:59:03 2005
+++ src/thumbnail.cpp	Fri May 20 00:51:33 2005
@@ -11,6 +11,7 @@
  */
 
 #include "thumbnail.h"
+#include <sys/types.h>
 #include <utime.h>
 
 int Thumbnail::thwidth = 100;
