--- src/pr_frontend.c.orig	2018-11-04 07:18:02 UTC
+++ src/pr_frontend.c
@@ -29,6 +29,8 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <sys/types.h>
+#include <netinet/in.h>

 #include "common.h"
 #include "lib_wrapper.h"
