--- utils/fstreewalk.cpp.orig	2021-08-03 07:29:21 UTC
+++ utils/fstreewalk.cpp
@@ -17,6 +17,7 @@
 
 #include "autoconfig.h"
 
+#include <sys/types.h>
 #include <stdio.h>
 
 #include <errno.h>
