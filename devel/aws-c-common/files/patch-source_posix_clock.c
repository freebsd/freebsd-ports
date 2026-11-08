--- source/posix/clock.c.orig	2026-08-25 23:01:05 UTC
+++ source/posix/clock.c
@@ -5,7 +5,7 @@
 
 #include <aws/common/clock.h>
 
-#include <time.h>
+#include <sys/time.h>
 
 static const uint64_t NS_PER_SEC = 1000000000;
 
