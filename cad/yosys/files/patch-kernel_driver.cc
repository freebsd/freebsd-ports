--- kernel/driver.cc.orig	2026-09-09 05:26:44 UTC
+++ kernel/driver.cc
@@ -20,7 +20,7 @@
 #include "kernel/yosys.h"
 #include "kernel/hashlib.h"
 #define CXXOPTS_VECTOR_DELIMITER '\0'
-#include "libs/cxxopts/include/cxxopts.hpp"
+#include <cxxopts.hpp>
 #include <iostream>
 #include <chrono>
 
