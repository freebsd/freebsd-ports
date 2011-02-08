--- src/output/httpd_output_plugin.c.orig
+++ src/output/httpd_output_plugin.c
@@ -32,6 +32,7 @@
 #include <assert.h>
 
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <unistd.h>
 #include <errno.h>
 
