--- src/utils.c.orig	Fri Jul 20 11:14:59 2001
+++ src/utils.c	Fri Jul 20 11:15:37 2001
@@ -25,6 +25,7 @@
 #include "utils.h"
 #include <unistd.h>
 #include <stdio.h>
+#include <errno.h>
 
 /*
  * tmalloc: mallocs cleanly
