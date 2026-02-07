--- cmake/TargetSetup.cmake.orig	2020-10-22 23:20:06 UTC
+++ cmake/TargetSetup.cmake
@@ -39,14 +39,14 @@ elseif(_wx_selected_config MATCHES "androideabi-qt")
      endif(ANDROID_ARCH MATCHES "arm64")
         
 elseif (UNIX)
-    find_program(LSB_RELEASE NAMES lsb_release)
-    if (NOT LSB_RELEASE)
-        message(FATAL_ERROR
-                "Cannot find the lsb_release program, please install.")
-    endif ()
-    execute_process(COMMAND ${LSB_RELEASE} "-is"
+#    find_program(LSB_RELEASE NAMES lsb_release)
+#    if (NOT LSB_RELEASE)
+#        message(FATAL_ERROR
+#                "Cannot find the lsb_release program, please install.")
+#    endif ()
+    execute_process(COMMAND uname "-i"
                     OUTPUT_VARIABLE PKG_TARGET)
-    execute_process(COMMAND ${LSB_RELEASE} "-rs"
+    execute_process(COMMAND uname "-r"
                     OUTPUT_VARIABLE PKG_TARGET_VERSION)
 else ()
     set(PKG_TARGET "unknown")
