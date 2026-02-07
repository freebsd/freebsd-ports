--- modules/javafx.web/src/main/native/Source/bmalloc/bmalloc/bmalloc.h.orig	2020-07-24 18:56:22 UTC
+++ modules/javafx.web/src/main/native/Source/bmalloc/bmalloc/bmalloc.h
@@ -111,7 +111,7 @@ inline size_t availableMemory()
     return bmalloc::availableMemory();
 }
 
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) ||  BOS(FREEBSD)
 inline size_t memoryFootprint()
 {
     return bmalloc::memoryFootprint();
