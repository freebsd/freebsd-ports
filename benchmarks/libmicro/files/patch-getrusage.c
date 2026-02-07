--- getrusage.c.orig	2011-05-11 00:58:23 UTC
+++ getrusage.c
@@ -36,6 +36,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 
 #include "libmicro.h"
