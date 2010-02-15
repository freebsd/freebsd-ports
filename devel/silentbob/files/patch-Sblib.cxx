--- sblib/Sblib.cxx.orig	2010-01-11 21:35:00.000000000 +0900
+++ sblib/Sblib.cxx	2010-02-12 20:11:43.000000000 +0900
@@ -293,7 +293,7 @@
 			lseek (fd, 0, SEEK_END);
 		dup2 (devnull, 2);
 		dup2 (fd, 1);
-		execlp ("find", "find", "-name", name, NULL);
+		execlp ("find", "find", path, "-name", name, NULL);
 	} else if (pid > 0) {
 		waitpid (pid, &status, 0);
 		return status;
