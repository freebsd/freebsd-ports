--- common/error.cc.orig	Tue Jan 14 00:59:18 2003
+++ common/error.cc	Tue Jan 14 00:59:40 2003
@@ -28,6 +28,7 @@
 #include <ac/stdlib.h>
 #include <ac/string.h>
 
+#include <sys/types.h>
 #include <grp.h>
 #include <pwd.h>
 #include <ac/unistd.h>
