--- hphp/runtime/ext/ext_posix.cpp.orig	2013-07-21 13:35:52.420426882 +0200
+++ hphp/runtime/ext/ext_posix.cpp	2013-07-21 13:36:48.030517355 +0200
@@ -20,6 +20,7 @@
 #include <sys/times.h>
 #include <sys/utsname.h>
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/time.h>
 #include <pwd.h>
 #include <memory>
