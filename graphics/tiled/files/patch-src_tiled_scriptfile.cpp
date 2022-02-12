--- src/tiled/scriptfile.cpp.orig	2022-02-11 12:24:45 UTC
+++ src/tiled/scriptfile.cpp
@@ -46,6 +46,7 @@
 #if defined(Q_OS_UNIX)
 #include <sys/stat.h>
 #include <unistd.h>
+#include <errno.h>
 #endif
 
 #include <memory>
