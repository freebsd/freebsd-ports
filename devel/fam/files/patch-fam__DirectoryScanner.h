--- ./fam/DirectoryScanner.h.orig	2003-04-15 06:21:30.000000000 +0200
+++ ./fam/DirectoryScanner.h	2014-01-03 02:35:10.000000000 +0100
@@ -27,7 +27,7 @@
 
 #include <stddef.h>
 #include <sys/types.h>
-#include <sys/dir.h>
+#include <dirent.h>
 
 #include "Event.h"
 
