--- src/App/ApplicationDirectories.cpp.orig	2026-01-01 15:27:46 UTC
+++ src/App/ApplicationDirectories.cpp
@@ -32,6 +32,7 @@
 
 #if defined(FC_OS_LINUX) || defined(FC_OS_MACOSX) || defined(FC_OS_BSD)
 #include <pwd.h>
+#include <sys/sysctl.h>
 #endif
 
 #include <Base/FileInfo.h>
