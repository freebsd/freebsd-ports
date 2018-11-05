--- team-framework/io/unixoutstreambuf.cpp.orig	2005-07-09 11:46:12 UTC
+++ team-framework/io/unixoutstreambuf.cpp
@@ -28,8 +28,11 @@
 #include <common.h>
 
 #include "unixoutstreambuf.h"
+#include <cstring>
 #include <sstream>
 #include <errno.h>
+#include <sys/types.h>
+#include <unistd.h>
 /**
  * Namespace
  */
