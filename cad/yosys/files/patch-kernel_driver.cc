--- kernel/driver.cc.orig	2025-04-09 05:38:42 UTC
+++ kernel/driver.cc
@@ -20,7 +20,7 @@
 #include "kernel/yosys.h"
 #include "kernel/hashlib.h"
 #include "libs/sha1/sha1.h"
-#include "libs/cxxopts/include/cxxopts.hpp"
+#include <cxxopts.hpp>
 #include <iostream>
 
 #ifdef YOSYS_ENABLE_READLINE
