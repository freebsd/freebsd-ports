--- src/include/panoinc.h.orig      Wed Mar  2 23:04:45 2005
+++ src/include/panoinc.h   Wed Mar  2 23:05:09 2005
@@ -32,6 +32,8 @@
 #ifdef __unix__
 #include <sys/time.h>
 #include <sys/resource.h>
+#include <sys/types.h>
+#include <sys/wait.h>
 #endif
 
 #include <vector>
