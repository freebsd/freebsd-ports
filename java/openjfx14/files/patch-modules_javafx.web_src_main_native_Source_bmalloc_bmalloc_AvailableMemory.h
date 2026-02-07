--- modules/javafx.web/src/main/native/Source/bmalloc/bmalloc/AvailableMemory.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/bmalloc/bmalloc/AvailableMemory.h
@@ -32,7 +32,7 @@ namespace bmalloc {
 
 size_t availableMemory();
 
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD)
 struct MemoryStatus {
     MemoryStatus(size_t memoryFootprint, double percentAvailableMemoryInUse)
         : memoryFootprint(memoryFootprint)
@@ -61,7 +61,7 @@ inline double percentAvailableMemoryInUse()
 
 inline bool isUnderMemoryPressure()
 {
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD)
     return percentAvailableMemoryInUse() > memoryPressureThreshold;
 #else
     return false;
