--- amarok/src/vis/xmmswrapper/xmmswrapper.cpp.orig	Mon Oct 18 13:37:03 2004
+++ amarok/src/vis/xmmswrapper/xmmswrapper.cpp	Mon Oct 18 13:37:36 2004
@@ -8,6 +8,7 @@
 #include <dirent.h>
 #include <dlfcn.h>           //dlopen etc.
 #include <stdlib.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/un.h>
