--- polyp/pid.c.orig	Fri Dec 31 15:36:25 2004
+++ polyp/pid.c	Fri Dec 31 15:36:37 2004
@@ -32,6 +32,7 @@
 #include <assert.h>
 #include <stdlib.h>
 #include <limits.h>
+#include <sys/stat.h>
 #include <signal.h>
 
 #include "pid.h"
