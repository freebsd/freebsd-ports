$FreeBSD$

--- server.cpp.orig	Sat Nov 16 07:55:37 2002
+++ server.cpp	Fri Nov 22 14:20:07 2002
@@ -24,6 +24,7 @@
  * USA
  */
 
+#include <errno.h>
 #include <cache.h>
 #include <sys/types.h>
 #include <sys/stat.h>
