
$FreeBSD$

--- mpg321.h.orig	Sat Sep 22 22:39:04 2001
+++ mpg321.h	Mon Sep 24 16:06:19 2001
@@ -32,6 +32,7 @@
 #include "config.h"
 #endif
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <limits.h>
 #include <ao/ao.h>
