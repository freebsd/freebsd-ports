--- source/posix/clock.c.orig	2019-02-17 20:17:45 UTC
+++ source/posix/clock.c
@@ -15,7 +15,7 @@
 
 #include <aws/common/clock.h>
 
-#include <time.h>
+#include <sys/time.h>
 
 static const uint64_t NS_PER_SEC = 1000000000;
 
