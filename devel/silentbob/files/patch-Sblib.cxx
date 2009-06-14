--- sblib/Sblib.cxx.orig	2009-04-04 17:46:58.000000000 +0900
+++ sblib/Sblib.cxx	2009-06-13 02:15:32.000000000 +0900
@@ -363,7 +363,7 @@
 			lseek (fd, 0, SEEK_END);
 		dup2 (devnull, 2);
 		dup2 (fd, 1);
-		execlp ("find", "find", "-name", name, NULL);
+		execlp ("find", "find", path, "-name", name, NULL);
 	} else if (pid > 0) {
 		waitpid (pid, &status, 0);
 		return status;
