--- jeeps/gpslibusb.cc.orig	2014-09-16 05:49:59.000000000 +0200
+++ jeeps/gpslibusb.cc	2015-03-14 19:33:11.690407708 +0100
@@ -20,7 +20,8 @@
  */
 
 
-#include <stdio.h>
+#include <cstdio>
+#include <cstdlib>
 #include <ctype.h>
 #if HAVE_CONFIG_H
 #include "config.h"
