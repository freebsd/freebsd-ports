--- cmake/GitWatcher.cmake.orig	2022-08-04 11:21:27 UTC
+++ cmake/GitWatcher.cmake
@@ -72,7 +72,7 @@ if(NOT DEFINED GIT_EXECUTABLE)
 # Check the optional git variable.
 # If it's not set, we'll try to find it using the CMake packaging system.
 if(NOT DEFINED GIT_EXECUTABLE)
-    find_package(Git QUIET REQUIRED)
+    find_package(Git)
 endif()
 CHECK_REQUIRED_VARIABLE(GIT_EXECUTABLE)
 
@@ -326,5 +326,13 @@ endfunction()
     endif()
 endfunction()
 
+# Archives fetched from GitHub lack Git metadata, just fill in the values
+# from the environment.
+function(NoGitBuild)
+    if(NOT EXISTS "${GIT_POST_CONFIGURE_FILE}")
+        GitStateChangedAction()
+    endif()
+endfunction()
+
 # And off we go...
-Main()
+NoGitBuild()
