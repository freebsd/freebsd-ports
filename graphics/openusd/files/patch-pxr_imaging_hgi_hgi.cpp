--- pxr/imaging/hgi/hgi.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/imaging/hgi/hgi.cpp
@@ -54,7 +54,7 @@ _MakeNewPlatformDefaultHgi()
     PlugRegistry& plugReg = PlugRegistry::GetInstance();
 
     const char* hgiType = 
-        #if defined(ARCH_OS_LINUX)
+        #if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
             "HgiGL";
         #elif defined(ARCH_OS_DARWIN)
             "HgiMetal";
