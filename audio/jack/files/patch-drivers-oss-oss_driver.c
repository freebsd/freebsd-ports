--- drivers/oss/oss_driver.c.orig	Sat May  1 10:53:47 2004
+++ drivers/oss/oss_driver.c	Sat May  1 10:58:57 2004
@@ -23,6 +23,7 @@
 
 #include <config.h>
 
+#define __BSD_VISIBLE	1
 #ifdef USE_BARRIER
 /*
  * POSIX conformance level should be globally defined somewhere, possibly
