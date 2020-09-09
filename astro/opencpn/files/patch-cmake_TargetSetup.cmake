--- cmake/TargetSetup.cmake.orig	2020-07-15 18:02:29 UTC
+++ cmake/TargetSetup.cmake
@@ -26,14 +26,10 @@ elseif (APPLE)
     execute_process(COMMAND "sw_vers" "-productVersion"
                     OUTPUT_VARIABLE PKG_TARGET_VERSION)
 elseif (UNIX)
-    find_program(LSB_RELEASE NAMES lsb_release)
-    if (NOT LSB_RELEASE)
-        message(FATAL_ERROR
-                "Cannot find the lsb_release program, please install.")
-    endif ()
-    execute_process(COMMAND ${LSB_RELEASE} "-is"
+    find_program(LSB_RELEASE NAMES uname)
+    execute_process(COMMAND ${LSB_RELEASE} "-s"
                     OUTPUT_VARIABLE PKG_TARGET)
-    execute_process(COMMAND ${LSB_RELEASE} "-rs"
+    execute_process(COMMAND ${LSB_RELEASE} "-r"
                     OUTPUT_VARIABLE PKG_TARGET_VERSION)
 else ()
     set(PKG_TARGET "unknown")
