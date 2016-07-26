--- src/utils.c.orig	2001-08-17 20:44:09 UTC
+++ src/utils.c
@@ -25,6 +25,7 @@
 #include "utils.h"
 #include <unistd.h>
 #include <stdio.h>
+#include <errno.h>
 
 /*
  * tmalloc: mallocs cleanly
