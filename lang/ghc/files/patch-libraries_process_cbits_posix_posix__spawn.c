https://github.com/haskell/process/pull/387

Can be removed after FreeBSD 14 and 15.1 go EoL.

--- libraries/process/cbits/posix/posix_spawn.c.orig	2026-03-26 05:07:53 UTC
+++ libraries/process/cbits/posix/posix_spawn.c
@@ -114,6 +114,9 @@ do_spawn_posix (char *const args[],
         // TODO: can this be efficiently supported?
         return -2;
     }
+#if __FreeBSD_version < 1600000
+    return -2;
+#endif
 
     // Now the main act...
     pid_t pid;
