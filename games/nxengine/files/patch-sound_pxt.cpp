--- sound/pxt.cpp.orig	2012-04-29 19:01:52 UTC
+++ sound/pxt.cpp
@@ -6,7 +6,7 @@
 #include <math.h>			// for sin()
 #include <stdlib.h>
 #include <string.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #include "../config.h"
 #include "pxt.h"
