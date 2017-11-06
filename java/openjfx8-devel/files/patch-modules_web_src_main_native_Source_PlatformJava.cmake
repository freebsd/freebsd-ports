--- modules/web/src/main/native/Source/PlatformJava.cmake.orig	2017-09-08 16:56:55 UTC
+++ modules/web/src/main/native/Source/PlatformJava.cmake
@@ -1,5 +1,5 @@
-add_subdirectory(ThirdParty/sqlite)
-add_subdirectory(ThirdParty/icu)
+# add_subdirectory(ThirdParty/sqlite)
+# add_subdirectory(ThirdParty/icu)
 
 # libxml2 should be compiled only on windows
 if (WIN32)
