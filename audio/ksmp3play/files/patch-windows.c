--- windows.c.orig	Mon Aug 20 02:43:24 2001
+++ windows.c	Sun Dec 29 12:45:25 2002
@@ -22,7 +22,7 @@
 #include "ksmp3play.h"
 
 #include <sys/types.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <sys/param.h>
 #include <stdio.h>
 #include <unistd.h>
