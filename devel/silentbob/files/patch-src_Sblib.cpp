--- src/Sblib.cpp.orig	2023-08-03 02:03:35 UTC
+++ src/Sblib.cpp
@@ -125,7 +125,7 @@ int sblib_find (const char * path, const char * name, 
 			lseek (fd, 0, SEEK_END);
 		dup2 (devnull, 2);
 		dup2 (fd, 1);
-		execlp ("find", "find", "-name", name, NULL);
+		execlp ("find", "find", path, "-name", name, NULL);
 	} else if (pid > 0) {
 		waitpid (pid, &status, 0);
 		return status;
