--- common.h.orig
+++ common.h
@@ -38,7 +38,12 @@
 #include <fcntl.h>
 #include <map>
 #include <pthread.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+#ifndef BSD
 #include <stdint.h>
+#endif
 #include <string>
 #include <sys/stat.h>
 #include <sys/time.h>
