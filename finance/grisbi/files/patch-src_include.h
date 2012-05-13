--- ./src/include.h.orig	2011-12-30 14:48:07.000000000 +0100
+++ ./src/include.h	2012-05-13 17:45:54.000000000 +0200
@@ -13,7 +13,9 @@
 #  include <string.h>
 #endif
 #include <sys/types.h>
-#include <sys/timeb.h>
+#ifndef __FreeBSD__
+#  include <sys/timeb.h>
+#endif
 #include <time.h>
 #include <sys/stat.h>
 #ifndef _MSC_VER
