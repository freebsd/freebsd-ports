--- src/misc/configuration.cxx.orig	2025-11-27 19:20:48 UTC
+++ src/misc/configuration.cxx
@@ -59,6 +59,12 @@
 #include <map>
 #include <sstream>
 
+#ifdef __FreeBSD__
+
+#  include <glob.h>
+
+#endif
+
 #ifdef __linux__
 
 #  include <dirent.h>
