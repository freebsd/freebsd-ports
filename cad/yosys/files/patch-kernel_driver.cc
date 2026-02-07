--- kernel/driver.cc.orig	2025-09-04 06:00:38 UTC
+++ kernel/driver.cc
@@ -21,7 +21,7 @@
 #include "kernel/hashlib.h"
 #include "libs/sha1/sha1.h"
 #define CXXOPTS_VECTOR_DELIMITER '\0'
-#include "libs/cxxopts/include/cxxopts.hpp"
+#include <cxxopts.hpp>
 #include <iostream>
 
 #ifdef YOSYS_ENABLE_READLINE
