--- fam/Directory.c++.orig	Tue Apr 15 10:21:29 2003
+++ fam/Directory.c++	Sat Aug 12 00:10:16 2006
@@ -26,7 +26,7 @@
 #include <errno.h>
 #include <string.h>
 #include <stdio.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <unistd.h>
