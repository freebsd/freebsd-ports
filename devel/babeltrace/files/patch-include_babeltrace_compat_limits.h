--- include/babeltrace/compat/limits.h.orig	2016-11-30 13:02:44 UTC
+++ include/babeltrace/compat/limits.h
@@ -31,6 +31,7 @@
 
 #elif defined(__FreeBSD__)
 
+#include <sys/param.h>
 #define BABELTRACE_HOST_NAME_MAX MAXHOSTNAMELEN
 
 #elif defined(_POSIX_HOST_NAME_MAX)
