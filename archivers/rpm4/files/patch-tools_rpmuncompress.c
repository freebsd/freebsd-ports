--- tools/rpmuncompress.c.orig	2023-12-19 16:39:32 UTC
+++ tools/rpmuncompress.c
@@ -1,8 +1,10 @@
 #include "system.h"
 
+#include <sys/wait.h>
 #include <popt.h>
 #include <libgen.h>
 #include <errno.h>
+#include <libgen.h>
 #include <stdio.h>
 #include <string.h>
 
