--- src/Sblib.cxx.orig	2013-11-27 15:00:47 UTC
+++ src/Sblib.cxx
@@ -125,7 +125,7 @@ int sblib_find (const char * path, const
 			lseek (fd, 0, SEEK_END);
 		dup2 (devnull, 2);
 		dup2 (fd, 1);
-		execlp ("find", "find", "-name", name, NULL);
+		execlp ("find", "find", path, "-name", name, NULL);
 	} else if (pid > 0) {
 		waitpid (pid, &status, 0);
 		return status;
