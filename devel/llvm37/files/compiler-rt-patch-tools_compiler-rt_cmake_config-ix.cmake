--- tools/compiler-rt/cmake/config-ix.cmake.orig	2015-08-20 13:35:01 UTC
+++ tools/compiler-rt/cmake/config-ix.cmake
@@ -180,8 +180,8 @@ elseif(NOT APPLE) # Supported archs for 
       # FIXME: We build runtimes for both i686 and i386, as "clang -m32" may
       # target different variant than "$CMAKE_C_COMPILER -m32". This part should
       # be gone after we resolve PR14109.
-      test_target_arch(i686 __i686__ "-m32")
-      test_target_arch(i386 __i386__ "-m32")
+      #test_target_arch(i686 __i686__ "-m32")
+      #test_target_arch(i386 __i386__ "-m32")
     else()
       if (CMAKE_SIZEOF_VOID_P EQUAL 4)
         test_target_arch(i386 "" "")
