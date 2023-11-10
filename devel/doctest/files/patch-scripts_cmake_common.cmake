- workaround for https://github.com/doctest/doctest/issues/828

--- scripts/cmake/common.cmake.orig	2023-11-09 05:34:19 UTC
+++ scripts/cmake/common.cmake
@@ -79,7 +79,7 @@ macro(add_compiler_flags)
 endmacro()
 
 if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
-    add_compiler_flags(-Werror)
+    #add_compiler_flags(-Werror)
     add_compiler_flags(-fstrict-aliasing)
 
     # The following options are not valid when clang-cl is used.
