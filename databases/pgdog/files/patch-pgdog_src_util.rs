Fix build under FreeBSD (https://github.com/pgdogdev/pgdog/pull/1785)
Fix https://github.com/pgdogdev/pgdog/issues/1784
--- pgdog/src/util.rs.orig	2026-10-14 07:47:59 UTC
+++ pgdog/src/util.rs
@@ -276,12 +276,12 @@ pub(crate) fn raise_nofile_limit() -> u64 {
                     "failed to raise NOFILE soft limit from {} to {}",
                     prev, rlim.rlim_max
                 );
-                return prev;
+                return prev as u64;
             }
         }
     }
 
-    rlim.rlim_cur
+    rlim.rlim_cur as u64
 }
 
 #[cfg(not(unix))]
