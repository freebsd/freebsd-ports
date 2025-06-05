--- lib/mount_bsd.c.orig	2025-03-24 12:25:30 UTC
+++ lib/mount_bsd.c
@@ -214,6 +214,7 @@ mount:
 			_exit(EXIT_FAILURE);
 		}
 
+		waitpid(pid, &status, 0);
 		_exit(EXIT_SUCCESS);
 	}
 
