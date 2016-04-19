--- Sources/Host/POSIX/Platform.cpp.orig	2015-10-28 07:56:02 UTC
+++ Sources/Host/POSIX/Platform.cpp
@@ -12,6 +12,7 @@
 #include "DebugServer2/Host/Platform.h"
 #include "DebugServer2/Utils/Log.h"
 
+#include <cerrno>
 #include <cstring>
 #include <fcntl.h>
 #include <grp.h>
