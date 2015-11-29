--- windows.c.orig	2008-06-17 05:57:56 UTC
+++ windows.c
@@ -30,7 +30,7 @@
 #include "ksmp3play.h"
 
 #include <sys/types.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <sys/param.h>
 #include <stdio.h>
 #include <unistd.h>
