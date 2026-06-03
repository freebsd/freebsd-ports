--- src/VBox/Frontends/VBoxHeadless/VBoxHeadless.cpp.orig	2025-08-13 19:50:04 UTC
+++ src/VBox/Frontends/VBoxHeadless/VBoxHeadless.cpp
@@ -63,7 +63,7 @@ using namespace com;
 # include <iprt/process.h>
 #endif
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
 # include <cerrno>
 #endif
 
