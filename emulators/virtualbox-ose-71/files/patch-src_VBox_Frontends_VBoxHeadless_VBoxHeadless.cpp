--- src/VBox/Frontends/VBoxHeadless/VBoxHeadless.cpp.orig	2024-12-26 22:32:13.106542000 +0100
+++ src/VBox/Frontends/VBoxHeadless/VBoxHeadless.cpp	2024-12-26 22:32:32.805126000 +0100
@@ -61,7 +61,7 @@
 # include <iprt/process.h>
 #endif
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
 # include <cerrno>
 #endif
 
