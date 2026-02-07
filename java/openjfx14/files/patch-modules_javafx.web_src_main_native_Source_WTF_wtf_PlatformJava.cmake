--- modules/javafx.web/src/main/native/Source/WTF/wtf/PlatformJava.cmake.orig	2020-07-24 19:01:56 UTC
+++ modules/javafx.web/src/main/native/Source/WTF/wtf/PlatformJava.cmake
@@ -83,9 +83,8 @@ elseif (UNIX)
     list(APPEND WTF_SOURCES
         generic/RunLoopGeneric.cpp
         generic/WorkQueueGeneric.cpp
-        linux/CurrentProcessMemoryStatus.cpp
-        linux/MemoryFootprintLinux.cpp
-        linux/MemoryPressureHandlerLinux.cpp
+        generic/MemoryFootprintGeneric.cpp
+        unix/MemoryPressureHandlerUnix.cpp
         unix/CPUTimeUnix.cpp
         unix/LanguageUnix.cpp
     )
