--- src/tm/dump_legacy_tm.cpp.orig	2015-08-03 10:49:16 UTC
+++ src/tm/dump_legacy_tm.cpp
@@ -28,6 +28,7 @@
 #include <string>
 #include <vector>
 
+#include <errno.h>
 #include <string.h>
 
 #ifdef DB_HEADER
