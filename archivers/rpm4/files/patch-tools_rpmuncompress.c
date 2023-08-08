--- tools/rpmuncompress.c.orig	2022-08-30 11:42:23 UTC
+++ tools/rpmuncompress.c
@@ -1,7 +1,9 @@
 #include "system.h"
 
+#include <sys/wait.h>
 #include <popt.h>
 #include <errno.h>
+#include <libgen.h>
 #include <stdio.h>
 #include <string.h>
 
