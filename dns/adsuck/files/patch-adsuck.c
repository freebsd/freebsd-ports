--- adsuck.c.orig	2011-04-14 20:36:30.000000000 +0200
+++ adsuck.c	2011-04-22 13:54:41.350251199 +0200
@@ -33 +33,2 @@
-#ifndef __linux__
+#include <signal.h>
+#include <limits.h>
@@ -35,4 +35,0 @@
-#include <sys/queue.h>
-#else
-#include <linux/limits.h>
-#include "linux/tree.h"
@@ -40 +36,0 @@
-#endif
