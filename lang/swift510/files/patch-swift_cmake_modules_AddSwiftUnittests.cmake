--- swift/cmake/modules/AddSwiftUnittests.cmake.orig	2024-06-06 04:26:30 UTC
+++ swift/cmake/modules/AddSwiftUnittests.cmake
@@ -32,6 +32,8 @@ function(add_swift_unittest test_dirname)
   # function defined by AddLLVM.cmake.
   add_unittest(SwiftUnitTests ${test_dirname} ${ASU_UNPARSED_ARGUMENTS})
 
+  target_link_options(${test_dirname} PRIVATE "SHELL:-Xlinker -z" "SHELL:-Xlinker nostart-stop-gc")
+
   set_target_properties(${test_dirname} PROPERTIES LINKER_LANGUAGE CXX)
 
   # TODO: _add_variant_c_compile_link_flags and these tests should share some
