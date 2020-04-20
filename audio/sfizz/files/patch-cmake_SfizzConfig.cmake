--- cmake/SfizzConfig.cmake.orig	2020-04-20 01:18:25 UTC
+++ cmake/SfizzConfig.cmake
@@ -67,7 +67,7 @@ if (USE_LIBCPP)
 add_compile_options(-stdlib=libc++)
 # Presumably need the above for linking too, maybe other options missing as well
 add_link_options(-stdlib=libc++)   # New command on CMake master, not in 3.12 release
-add_link_options(-lc++abi)   # New command on CMake master, not in 3.12 release
+#add_link_options(-lc++abi)   # New command on CMake master, not in 3.12 release
 endif()
 endif()
 
