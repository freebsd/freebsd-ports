--- tests/radeon/radeon_ttm.c.orig	2013-11-07 11:34:28.207096353 +0100
+++ tests/radeon/radeon_ttm.c	2013-11-07 11:37:41.571085931 +0100
@@ -25,6 +25,10 @@
  */
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
+
+#include <xf86drm.h>
+
 #include "rbo.h"
 
 /* allocate as many single page bo to try to starve the kernel
