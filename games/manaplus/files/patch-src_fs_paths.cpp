--- src/fs/paths.cpp.orig	2017-02-27 21:31:48 UTC
+++ src/fs/paths.cpp
@@ -51,6 +51,7 @@
 #ifndef WIN32
 #include <sys/types.h>
 #include <pwd.h>
+#include <unistd.h>
 #endif  // WIN32
 
 #ifdef ANDROID
