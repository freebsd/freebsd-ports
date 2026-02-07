--- rigs/dummy/rot_pstrotator.c.orig	2025-02-09 21:22:13 UTC
+++ rigs/dummy/rot_pstrotator.c
@@ -23,6 +23,7 @@
 #include <math.h>
 #include <sys/time.h>
 #include <errno.h>
+#include <sys/socket.h>
 
 #include "hamlib/rotator.h"
 #include "dummy_common.h"
