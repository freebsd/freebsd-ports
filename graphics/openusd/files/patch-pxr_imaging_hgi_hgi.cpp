--- pxr/imaging/hgi/hgi.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/imaging/hgi/hgi.cpp
@@ -187,7 +187,7 @@ _MakeNewPlatformDefaultHgi()
     PlugRegistry& plugReg = PlugRegistry::GetInstance();
 
     const char* hgiType = 
-        #if defined(ARCH_OS_LINUX)
+        #if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
             "HgiGL";
         #elif defined(ARCH_OS_DARWIN)
             "HgiMetal";
