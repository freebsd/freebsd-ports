--- PreLoad.cmake.orig	2025-11-09 11:45:34 UTC
+++ PreLoad.cmake
@@ -19,45 +19,49 @@ endif()
     endif ()
 endif()
 
-# Check if environment is polluted.
-if (NOT "$ENV{CFLAGS}" STREQUAL ""
-    OR NOT "$ENV{CXXFLAGS}" STREQUAL ""
-    OR NOT "$ENV{LDFLAGS}" STREQUAL ""
-    OR CMAKE_C_FLAGS OR CMAKE_CXX_FLAGS OR CMAKE_EXE_LINKER_FLAGS OR CMAKE_SHARED_LINKER_FLAGS OR CMAKE_MODULE_LINKER_FLAGS
-    OR CMAKE_C_FLAGS_INIT OR CMAKE_CXX_FLAGS_INIT OR CMAKE_EXE_LINKER_FLAGS_INIT OR CMAKE_SHARED_LINKER_FLAGS_INIT OR CMAKE_MODULE_LINKER_FLAGS_INIT)
+# Default toolchain - this is needed to avoid dependency on OS files.
+execute_process(COMMAND uname -s OUTPUT_VARIABLE OS)
+execute_process(COMMAND uname -m OUTPUT_VARIABLE ARCH)
 
-    # if $ENV
-    message("CFLAGS: $ENV{CFLAGS}")
-    message("CXXFLAGS: $ENV{CXXFLAGS}")
-    message("LDFLAGS: $ENV{LDFLAGS}")
-    # if *_FLAGS
-    message("CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
-    message("CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
-    message("CMAKE_EXE_LINKER_FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")
-    message("CMAKE_SHARED_LINKER_FLAGS: ${CMAKE_SHARED_LINKER_FLAGS}")
-    message("CMAKE_MODULE_LINKER_FLAGS: ${CMAKE_MODULE_LINKER_FLAGS}")
-    # if *_FLAGS_INIT
-    message("CMAKE_C_FLAGS_INIT: ${CMAKE_C_FLAGS_INIT}")
-    message("CMAKE_CXX_FLAGS_INIT: ${CMAKE_CXX_FLAGS_INIT}")
-    message("CMAKE_EXE_LINKER_FLAGS_INIT: ${CMAKE_EXE_LINKER_FLAGS_INIT}")
-    message("CMAKE_SHARED_LINKER_FLAGS_INIT: ${CMAKE_SHARED_LINKER_FLAGS_INIT}")
-    message("CMAKE_MODULE_LINKER_FLAGS_INIT: ${CMAKE_MODULE_LINKER_FLAGS_INIT}")
+if (OS MATCHES "FreeBSD")
+    message(STATUS "Skipping strict CFLAGS check on FreeBSD")
+else()
+	# Check if environment is polluted.
+	if (NOT "$ENV{CFLAGS}" STREQUAL ""
+    	OR NOT "$ENV{CXXFLAGS}" STREQUAL ""
+    	OR NOT "$ENV{LDFLAGS}" STREQUAL ""
+    	OR CMAKE_C_FLAGS OR CMAKE_CXX_FLAGS OR CMAKE_EXE_LINKER_FLAGS OR CMAKE_SHARED_LINKER_FLAGS OR CMAKE_MODULE_LINKER_FLAGS
+    	OR CMAKE_C_FLAGS_INIT OR CMAKE_CXX_FLAGS_INIT OR CMAKE_EXE_LINKER_FLAGS_INIT OR CMAKE_SHARED_LINKER_FLAGS_INIT OR CMAKE_MODULE_LINKER_FLAGS_INIT)
 
-    message(FATAL_ERROR "
-        Some of the variables like CFLAGS, CXXFLAGS, LDFLAGS are not empty.
-        It is not possible to build ClickHouse with custom flags.
-        These variables can be set up by previous invocation of some other build tools.
-        You should cleanup these variables and start over again.
+    	# if $ENV
+    	message("CFLAGS: $ENV{CFLAGS}")
+    	message("CXXFLAGS: $ENV{CXXFLAGS}")
+    	message("LDFLAGS: $ENV{LDFLAGS}")
+    	# if *_FLAGS
+    	message("CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
+    	message("CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
+    	message("CMAKE_EXE_LINKER_FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")
+    	message("CMAKE_SHARED_LINKER_FLAGS: ${CMAKE_SHARED_LINKER_FLAGS}")
+    	message("CMAKE_MODULE_LINKER_FLAGS: ${CMAKE_MODULE_LINKER_FLAGS}")
+    	# if *_FLAGS_INIT
+    	message("CMAKE_C_FLAGS_INIT: ${CMAKE_C_FLAGS_INIT}")
+    	message("CMAKE_CXX_FLAGS_INIT: ${CMAKE_CXX_FLAGS_INIT}")
+    	message("CMAKE_EXE_LINKER_FLAGS_INIT: ${CMAKE_EXE_LINKER_FLAGS_INIT}")
+	    message("CMAKE_SHARED_LINKER_FLAGS_INIT: ${CMAKE_SHARED_LINKER_FLAGS_INIT}")
+		message("CMAKE_MODULE_LINKER_FLAGS_INIT: ${CMAKE_MODULE_LINKER_FLAGS_INIT}")
 
-        Run the `env` command to check the details.
-        You will also need to remove the contents of the build directory.
+		message(FATAL_ERROR "
+        	Some of the variables like CFLAGS, CXXFLAGS, LDFLAGS are not empty.
+        	It is not possible to build ClickHouse with custom flags.
+        	These variables can be set up by previous invocation of some other build tools.
+        	You should cleanup these variables and start over again.
 
-        Note: if you don't like this behavior, you can manually edit the cmake files, but please don't complain to developers.")
-endif()
+        	Run the `env` command to check the details.
+        	You will also need to remove the contents of the build directory.
 
-# Default toolchain - this is needed to avoid dependency on OS files.
-execute_process(COMMAND uname -s OUTPUT_VARIABLE OS)
-execute_process(COMMAND uname -m OUTPUT_VARIABLE ARCH)
+        	Note: if you don't like this behavior, you can manually edit the cmake files, but please don't complain to developers.")
+	endif()
+endif()
 
 # By default, prefer clang on Linux
 # But note, that you still may change the compiler with -DCMAKE_C_COMPILER/-DCMAKE_CXX_COMPILER.
