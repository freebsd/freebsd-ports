--- dialog.c.orig	1996-11-16 05:37:15 UTC
+++ dialog.c
@@ -8,7 +8,7 @@
 
 #include        <sys/types.h>
 #include        <sys/stat.h>
-#include        <sys/dir.h>
+#include        <dirent.h>
 
 #include 	"gameheader.h"
 
@@ -430,7 +430,7 @@ void checkdir(dirname,fname,fflag)
      char    *fflag;
 {
   DIR           *dp;
-  struct direct *dir;
+  struct dirent *dir;
   struct stat   sbuf;
   char          newname[256];
   register      i = 0;
