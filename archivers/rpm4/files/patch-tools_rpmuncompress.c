--- tools/rpmuncompress.c.orig	2022-08-30 11:42:23 UTC
+++ tools/rpmuncompress.c
@@ -1,5 +1,6 @@
 #include "system.h"
 
+#include <sys/wait.h>
 #include <popt.h>
 #include <errno.h>
 #include <stdio.h>
