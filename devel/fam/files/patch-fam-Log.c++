--- fam/Log.c++~	Tue Jul 16 02:16:14 2002
+++ fam/Log.c++	Tue Sep  3 19:56:25 2002
@@ -28,9 +28,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
-#include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>
 #ifdef HAVE_AUDIT
