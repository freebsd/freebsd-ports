--- lib/external/libwolv/libs/io/include/wolv/io/file.hpp.orig	2023-05-21 12:25:30 UTC
+++ lib/external/libwolv/libs/io/include/wolv/io/file.hpp
@@ -10,6 +10,7 @@
 #include <vector>
 
 #include <sys/stat.h>
+#include "jthread.hpp"
 
 #if defined(OS_MACOS)
 
