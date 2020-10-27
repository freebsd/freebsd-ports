--- utils/fstreewalk.cpp.orig	2020-08-30 18:31:25 UTC
+++ utils/fstreewalk.cpp
@@ -17,6 +17,7 @@
 
 #include "autoconfig.h"
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <dirent.h>
 #include <errno.h>
