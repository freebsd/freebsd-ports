
$FreeBSD$

--- remote.c.orig	Mon Sep 24 16:06:46 2001
+++ remote.c	Mon Sep 24 16:06:48 2001
@@ -27,6 +27,7 @@
 
 #include "mpg321.h"
 
+#include <sys/time.h>
 #include <string.h>
 #include <unistd.h>
 
