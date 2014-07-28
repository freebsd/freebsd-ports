--- hsftp.c.orig	Sun Aug 27 13:06:30 2000
+++ hsftp.c	Sun Aug 27 13:06:42 2000
@@ -58,6 +58,7 @@
 #include <signal.h>
 #include <sys/types.h>
 #include <sys/mman.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 
 #include "config.h"
