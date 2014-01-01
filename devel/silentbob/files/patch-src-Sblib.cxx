--- src/Sblib.cxx.orig	2013-11-28 00:00:47.000000000 +0900
+++ src/Sblib.cxx	2013-12-03 11:42:09.000000000 +0900
@@ -125,7 +125,7 @@
 			lseek (fd, 0, SEEK_END);
 		dup2 (devnull, 2);
 		dup2 (fd, 1);
-		execlp ("find", "find", "-name", name, NULL);
+		execlp ("find", "find", path, "-name", name, NULL);
 	} else if (pid > 0) {
 		waitpid (pid, &status, 0);
 		return status;
