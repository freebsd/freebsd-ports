--- modules/javafx.web/src/main/native/Source/cmake/WebKitCommon.cmake.orig	2020-09-17 13:23:59 UTC
+++ modules/javafx.web/src/main/native/Source/cmake/WebKitCommon.cmake
@@ -17,8 +17,7 @@ if (NOT HAS_RUN_WEBKIT_COMMON)
     find_package(Perl 5.10.0 REQUIRED)
     find_package(PerlModules COMPONENTS JSON::PP REQUIRED)
 
-    set(Python_ADDITIONAL_VERSIONS 3)
-    find_package(PythonInterp 2.7.0 REQUIRED)
+    find_package(PythonInterp REQUIRED)
 
     # We cannot check for RUBY_FOUND because it is set only when the full package is installed and
     # the only thing we need is the interpreter. Unlike Python, cmake does not provide a macro
