--- getrusage.c.orig	Sat Aug  6 16:12:36 2005
+++ getrusage.c	Sat Aug  6 16:12:57 2005
@@ -40,6 +40,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 
 #include "libmicro.h"
