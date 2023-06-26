--- backends/pam/libpam_main.c.orig	2023-06-26 15:12:29 UTC
+++ backends/pam/libpam_main.c
@@ -47,6 +47,7 @@
 #include <pwd.h>
 #include <grp.h>
 #include <errno.h>
+#include <stdlib.h>
 #include <sys/types.h>
 
 #include <libwzd-core/wzd_backend.h>
