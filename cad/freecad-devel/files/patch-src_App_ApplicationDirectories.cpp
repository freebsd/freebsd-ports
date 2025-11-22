--- src/App/ApplicationDirectories.cpp.orig	2025-09-10 20:44:18 UTC
+++ src/App/ApplicationDirectories.cpp
@@ -33,6 +33,7 @@
 
 #if defined(FC_OS_LINUX) || defined(FC_OS_MACOSX) || defined(FC_OS_BSD)
 #include <pwd.h>
+#include <sys/sysctl.h>
 #endif
 
 #include <Base/FileInfo.h>
