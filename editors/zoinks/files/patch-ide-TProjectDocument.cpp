--- ide/TProjectDocument.cpp.orig	2007-11-04 22:37:49.000000000 +0100
+++ ide/TProjectDocument.cpp	2007-11-04 22:38:02.000000000 +0100
@@ -539,7 +539,7 @@
 				chdir(workingDirectory);
 
 				const char* command = fExternalDebuggerCommand;
-				execl("/bin/sh", "sh", "-c", command, NULL);
+				execl("/bin/sh", "sh", "-c", command, (char *)NULL);
 			}
 			else if (pid < 0)
 				ThrowSystemError(pid);
