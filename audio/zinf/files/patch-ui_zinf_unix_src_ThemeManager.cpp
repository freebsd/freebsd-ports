--- ui/zinf/unix/src/ThemeManager.cpp.orig	2003-09-16 20:36:23.000000000 +0300
+++ ui/zinf/unix/src/ThemeManager.cpp
@@ -28,6 +28,10 @@ ________________________________________
 #include <unistd.h>
 #include <netinet/in.h>
 #include <string>
+#include <cstring>
+extern "C" {
+#include <strings.h>
+}
 
 #ifndef WIN32
 #include <unistd.h>
