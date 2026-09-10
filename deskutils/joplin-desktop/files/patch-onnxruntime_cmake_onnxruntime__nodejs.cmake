--- onnxruntime/cmake/onnxruntime_nodejs.cmake.orig	2026-03-05 04:48:10 UTC
+++ onnxruntime/cmake/onnxruntime_nodejs.cmake
@@ -33,7 +33,7 @@ else()
 else()
     if(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
         set(NODEJS_BINDING_ARCH arm64)
-    elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
+    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64")
         set(NODEJS_BINDING_ARCH x64)
     else()
         message(FATAL_ERROR "Unsupported target platform for Node.js binding:" ${onnxruntime_target_platform})
@@ -82,18 +82,18 @@ if(NOT onnxruntime_ENABLE_STATIC_ANALYSIS)
 
 if(NOT onnxruntime_ENABLE_STATIC_ANALYSIS)
 # add custom target
-add_custom_target(js_npm_ci ALL
-    COMMAND ${NPM_CLI} ci
-    WORKING_DIRECTORY ${JS_ROOT}
-    COMMENT "NPM install on /js")
+# add_custom_target(js_npm_ci ALL
+#     COMMAND ${NPM_CLI} ci
+#     WORKING_DIRECTORY ${JS_ROOT}
+#     COMMENT "NPM install on /js")
 
-add_custom_target(js_common_npm_ci ALL
-    COMMAND ${NPM_CLI} ci
-    WORKING_DIRECTORY ${JS_COMMON_ROOT}
-    COMMENT "NPM install on /js/common")
+# add_custom_target(js_common_npm_ci ALL
+#     COMMAND ${NPM_CLI} ci
+#     WORKING_DIRECTORY ${JS_COMMON_ROOT}
+#     COMMENT "NPM install on /js/common")
 
 add_custom_target(nodejs_binding_wrapper ALL
-    COMMAND ${NPM_CLI} ci
+#     COMMAND ${NPM_CLI} ci
     COMMAND ${NPM_CLI} run build -- "--onnxruntime-build-dir=${CMAKE_CURRENT_BINARY_DIR}"
         --config=${CMAKE_BUILD_TYPE}
         "--onnxruntime-generator=${CMAKE_GENERATOR}"
@@ -103,7 +103,7 @@ add_custom_target(nodejs_binding_wrapper ALL
     WORKING_DIRECTORY ${JS_NODE_ROOT}
     COMMENT "Using cmake-js to build OnnxRuntime Node.js binding")
 
-add_dependencies(js_common_npm_ci js_npm_ci)
-add_dependencies(nodejs_binding_wrapper js_common_npm_ci)
+# add_dependencies(js_common_npm_ci js_npm_ci)
+# add_dependencies(nodejs_binding_wrapper js_common_npm_ci)
 add_dependencies(nodejs_binding_wrapper onnxruntime)
 endif()
