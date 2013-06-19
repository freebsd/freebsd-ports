--- ./ptex.imageio/ptex/PtexWriter.cpp.orig	2013-06-04 19:49:43.476382085 +0930
+++ ./ptex.imageio/ptex/PtexWriter.cpp	2013-06-04 19:49:48.134381870 +0930
@@ -66,6 +66,7 @@
 #include <algorithm>
 #include <iostream>
 #include <sstream>
+#include <unistd.h>
 
 #include "filesystem.h"
 
