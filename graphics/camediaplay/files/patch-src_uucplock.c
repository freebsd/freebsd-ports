--- ../src/uucplock.c.bak	1999-12-02 11:12:18.000000000 +0800
+++ ../src/uucplock.c	2011-09-16 09:09:05.000000000 +0800
@@ -37,9 +37,13 @@ static char sccsid[] = "@(#)uucplock.c	5
 
 #include "config.h"
 
+#include <sys/types.h>
+#include <stdio.h>
+#include <signal.h>
 #include <sys/file.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include "pathnames.h"
 
@@ -49,6 +53,7 @@ static char sccsid[] = "@(#)uucplock.c	5
  * 	  -1 - failure
  */
 
+int
 uu_lock(ttyname)
 	char *ttyname;
 {
@@ -101,6 +106,7 @@ uu_lock(ttyname)
 	return(0);
 }
 
+int
 uu_unlock(ttyname)
 	char *ttyname;
 {
