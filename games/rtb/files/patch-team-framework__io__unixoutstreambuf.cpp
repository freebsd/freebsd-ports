--- team-framework/io/unixoutstreambuf.cpp.orig
+++ team-framework/io/unixoutstreambuf.cpp
@@ -30,6 +30,8 @@
 #include "unixoutstreambuf.h"
 #include <sstream>
 #include <errno.h>
+#include <sys/types.h>
+#include <unistd.h>
 /**
  * Namespace
  */
