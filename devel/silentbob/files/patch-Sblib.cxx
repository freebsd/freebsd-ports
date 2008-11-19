--- sblib/Sblib.cxx.orig	2008-09-18 12:45:29.000000000 +0900
+++ sblib/Sblib.cxx	2008-11-13 15:53:16.000000000 +0900
@@ -346,7 +346,7 @@
 			lseek (fd, 0, SEEK_END);
 		dup2 (devnull, 2);
 		dup2 (fd, 1);
-		execlp ("find", path, "-name", name, NULL);
+		execlp ("find", "find", path, "-name", name, NULL);
 	} else if (pid > 0) {
 		waitpid (pid, &status, 0);
 		return status;
