--- execution/src/posix/execution.cc.orig	2019-08-10 21:37:06 UTC
+++ execution/src/posix/execution.cc
@@ -487,9 +487,14 @@ namespace leatherman { namespace execution {
                 kill(-child, SIGKILL);
             }
             // Wait for the child to exit
-            if (waitpid(child, &status, 0) == -1) {
-                LOG_DEBUG(format_error(_("waitpid failed")));
-                return;
+            while (waitpid(child, &status, 0) == -1) {
+                if ( errno == EINTR ) {
+                    LOG_DEBUG(format_error(_("waitpid was interrupted by a signal, retrying")));
+                    continue;
+                } else {
+                    LOG_DEBUG(format_error(_("waitpid failed")));
+                    return;
+                }
             }
             if (WIFEXITED(status)) {
                 status = static_cast<char>(WEXITSTATUS(status));
