--- utils/fileudi.cpp.orig	2014-07-07 16:10:11 UTC
+++ utils/fileudi.cpp
@@ -18,6 +18,7 @@
 
 #include <stdio.h>
 #include <cstdlib>
+#include <sys/types.h>
 
 #include "fileudi.h"
 #include "md5.h"
