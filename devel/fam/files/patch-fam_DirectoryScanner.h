--- fam/DirectoryScanner.h.orig	Tue Apr 15 10:21:30 2003
+++ fam/DirectoryScanner.h	Sat Aug 12 00:10:29 2006
@@ -27,7 +27,7 @@
 
 #include <stddef.h>
 #include <sys/types.h>
-#include <sys/dir.h>
+#include <dirent.h>
 
 #include "Event.h"
 
