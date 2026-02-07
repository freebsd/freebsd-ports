--- src/pulse/util.c.orig	2022-06-21 10:54:48 UTC
+++ src/pulse/util.c
@@ -30,6 +30,10 @@
 #include <time.h>
 #include <unistd.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
 
 #ifdef HAVE_PWD_H
 #include <pwd.h>
