--- fileBrowser.c.orig	2014-05-08 13:50:48 UTC
+++ fileBrowser.c
@@ -47,11 +47,7 @@ extern Xaw3dXftData *xaw3dxft_data;
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS )
 #include <dirent.h>
-#else
-#include <sys/dir.h>
-#endif
 #include <pwd.h>
 
 #include "rw/rwTable.h"
@@ -562,11 +558,7 @@ static void 
 setCWD(arg_t * arg, char *dir)
 {
     DIR *dirp;
-#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__)
     struct dirent *e;
-#else
-    struct direct *e;
-#endif
     int count = 0, i = 0;
     int dirCount = 0, fileCount = 0;
     String *list;
