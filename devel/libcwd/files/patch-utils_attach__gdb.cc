--- utils/attach_gdb.cc.orig	2016-01-13 00:40:18 UTC
+++ utils/attach_gdb.cc
@@ -13,6 +13,7 @@
 
 #include "sys.h"
 #include "cwd_debug.h"
+#include "signal.h"
 
 #ifdef _WIN32
 
