--- ui/musicbrowser/unix/src/fileselector.cpp.orig	2003-09-16 20:35:29.000000000 +0300
+++ ui/musicbrowser/unix/src/fileselector.cpp
@@ -25,7 +25,12 @@ ________________________________________
 #include <unistd.h>
 #include <dirent.h>
 #include <string>
+#include <cstring>
 #include <vector>
+
+extern "C" {
+#include <strings.h>
+}
 #ifdef __QNX__
 #include <strings.h>
 #endif
