--- client/vector/analyzeFuncs_sse.cpp.orig	2008-08-19 21:24:46.000000000 +0200
+++ client/vector/analyzeFuncs_sse.cpp	2012-04-19 12:51:10.000000000 +0200
@@ -32,6 +32,7 @@
 // This file is empty is __i386__ is not defined
 #include "sah_config.h"
 #include <vector>
+#include <math.h>
 
 #if defined(__i386__) || defined(__x86_64__)
 
