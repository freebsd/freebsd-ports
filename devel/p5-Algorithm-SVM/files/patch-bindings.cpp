--- bindings.cpp.orig	2008-01-23 00:14:34.000000000 +0300
+++ bindings.cpp	2014-03-01 04:05:30.166745426 +0400
@@ -1,5 +1,6 @@
 #include "bindings.h"
 #include <errno.h>
+#include <cstdlib>
 
 #ifdef DEBUG
 #include <stdarg.h>
