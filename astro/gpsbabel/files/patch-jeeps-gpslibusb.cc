--- jeeps/gpslibusb.cc.orig
+++ jeeps/gpslibusb.cc
@@ -20,8 +20,8 @@
  */
 
 
-#include <stdio.h>
-#include <stdlib.h>
+#include <cstdio>
+#include <cstdlib>
 #include <ctype.h>
 #if HAVE_CONFIG_H
 #include "config.h"
