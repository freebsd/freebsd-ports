diff -ruN fam/Log.c++ fam/Log.c++
--- fam/Log.c++	Wed May 29 00:20:30 2002
+++ fam/Log.c++	Sat Jun  8 16:31:07 2002
@@ -28,6 +28,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
+#include <sys/time.h>
+#include <sys/types.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
 #include <sys/time.h>
