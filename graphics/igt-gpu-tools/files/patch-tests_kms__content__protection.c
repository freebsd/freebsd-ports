--- tests/kms_content_protection.c.orig	2022-08-31 20:00:01 UTC
+++ tests/kms_content_protection.c
@@ -24,7 +24,9 @@
 
 #include <poll.h>
 #include <fcntl.h>
+#ifdef __linux__
 #include <sys/epoll.h>
+#endif
 #include <sys/stat.h>
 #include <libudev.h>
 #include "igt.h"
