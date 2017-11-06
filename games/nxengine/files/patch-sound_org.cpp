--- sound/org.cpp.orig	2012-04-29 19:01:52 UTC
+++ sound/org.cpp
@@ -4,7 +4,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #include "../common/basics.h"
 #include "org.h"
