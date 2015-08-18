--- jeeps/gpslibusb.cc.orig	2014-09-16 03:49:59 UTC
+++ jeeps/gpslibusb.cc
@@ -20,7 +20,8 @@
  */
 
 
-#include <stdio.h>
+#include <cstdio>
+#include <cstdlib>
 #include <ctype.h>
 #if HAVE_CONFIG_H
 #include "config.h"
