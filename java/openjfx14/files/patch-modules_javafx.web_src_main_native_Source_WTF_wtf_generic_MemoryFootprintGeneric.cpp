--- modules/javafx.web/src/main/native/Source/WTF/wtf/generic/MemoryFootprintGeneric.cpp.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/WTF/wtf/generic/MemoryFootprintGeneric.cpp
@@ -25,8 +25,9 @@
 
 #include "config.h"
 #include <wtf/MemoryFootprint.h>
+#include <wtf/Platform.h>
 
-#if !(defined(USE_SYSTEM_MALLOC) && USE_SYSTEM_MALLOC) && OS(LINUX)
+#if !USE(SYSTEM_MALLOC) && (OS(LINUX) || OS(FREEBSD))
 #include <bmalloc/bmalloc.h>
 #endif
 
@@ -34,7 +35,7 @@ namespace WTF {
 
 size_t memoryFootprint()
 {
-#if !(defined(USE_SYSTEM_MALLOC) && USE_SYSTEM_MALLOC) && OS(LINUX)
+#if !USE(SYSTEM_MALLOC) && (OS(LINUX) || OS(FREEBSD))
     return bmalloc::api::memoryFootprint();
 #else
     return 0;
