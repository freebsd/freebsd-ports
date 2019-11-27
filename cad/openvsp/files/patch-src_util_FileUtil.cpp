--- src/util/FileUtil.cpp.orig	2019-11-25 15:26:25 UTC
+++ src/util/FileUtil.cpp
@@ -21,6 +21,7 @@
 
 #ifdef __FreeBSD__
 #include <libgen.h>
+#include <sys/param.h>
 #endif
 
 vector< string > ScanFolder( const char* dir_path )
