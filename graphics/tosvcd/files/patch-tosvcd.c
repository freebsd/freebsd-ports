--- tosvcd.c.orig	Mon Dec  9 18:24:57 2002
+++ tosvcd.c	Sat Dec 14 07:21:57 2002
@@ -20,14 +20,12 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <string.h>
-#include <stdint.h>
 #include <sys/stat.h>
 #include <time.h>
 #include <pthread.h>
 #include <list>
-#include <values.h>
 #include <signal.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <glob.h>
 
 #include "mm_accel.h"
