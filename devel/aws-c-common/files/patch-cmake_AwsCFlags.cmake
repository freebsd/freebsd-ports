--- cmake/AwsCFlags.cmake.orig	2020-12-30 21:06:26 UTC
+++ cmake/AwsCFlags.cmake
@@ -73,7 +73,7 @@ function(aws_set_common_properties target)
 
        # -moutline-atomics generates code for both older load/store exclusive atomics and also
        # Arm's Large System Extensions (LSE) which scale substantially better on large core count systems
-        check_c_compiler_flag(-moutline-atomics HAS_MOUTLINE_ATOMICS)
+        check_c_compiler_flag("-moutline-atomics -Werror" HAS_MOUTLINE_ATOMICS)
         if (HAS_MOUTLINE_ATOMICS)
             list(APPEND AWS_C_FLAGS -moutline-atomics)
         endif()
