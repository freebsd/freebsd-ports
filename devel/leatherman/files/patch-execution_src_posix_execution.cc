--- execution/src/posix/execution.cc.orig	2018-09-29 16:21:31 UTC
+++ execution/src/posix/execution.cc
@@ -314,9 +314,7 @@ namespace leatherman { namespace executi
         }
 
         // Close all open file descriptors above stderr
-        for (uint64_t i = (STDERR_FILENO + 1); i < max_fd; ++i) {
-            close(i);
-        }
+        closefrom(STDERR_FILENO + 1);
 
         // Execute the given program; this should not return if successful
         execve(program, const_cast<char* const*>(argv), const_cast<char* const*>(envp));
