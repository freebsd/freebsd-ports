--- src/common/system/system.cpp.orig	2024-12-23 20:22:56 UTC
+++ src/common/system/system.cpp
@@ -24,7 +24,7 @@
 
 #if defined(PLATFORM_WINDOWS)
     #include "common/system/system_windows.h"
-#elif defined(PLATFORM_LINUX)
+#elif defined(PLATFORM_LINUX) || defined(PLATFORM_FREEBSD)
     #include "common/system/system_linux.h"
 #elif defined(PLATFORM_MACOSX)
     #include "common/system/system_macosx.h"
@@ -44,7 +44,7 @@ std::unique_ptr<CSystemUtils> CSystemUtils::Create()
     std::unique_ptr<CSystemUtils> instance;
 #if defined(PLATFORM_WINDOWS)
     instance = MakeUnique<CSystemUtilsWindows>();
-#elif defined(PLATFORM_LINUX)
+#elif defined(PLATFORM_LINUX) || defined(PLATFORM_FREEBSD)
     instance = MakeUnique<CSystemUtilsLinux>();
 #elif defined(PLATFORM_MACOSX)
     instance = MakeUnique<CSystemUtilsMacOSX>();
