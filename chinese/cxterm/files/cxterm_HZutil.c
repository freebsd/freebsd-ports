--- cxterm/HZutil.c.orig	1995-01-17 11:57:30.000000000 +0100
+++ cxterm/HZutil.c	2007-11-22 14:35:04.000000000 +0100
@@ -31,6 +31,7 @@
 
 #include "HZtable.h"
 #include <stdio.h>
+#include <string.h>
 #include <ctype.h>
 
 
@@ -153,6 +154,7 @@
 {
 
 #if !defined(X_NOT_POSIX) || defined(SYSV) || defined(USG)
+# include <stdlib.h>
 # include <dirent.h>
 #else
 # include <sys/dir.h>
