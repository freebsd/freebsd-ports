--- backend/src/ir/immediate.hpp.orig	2015-01-30 01:06:19.873878476 +0100
+++ backend/src/ir/immediate.hpp	2015-01-30 01:06:29.286877660 +0100
@@ -25,6 +25,7 @@
 #ifndef __GBE_IR_IMMEDIATE_HPP__
 #define __GBE_IR_IMMEDIATE_HPP__
 
+#include <cmath>
 #include <string.h>
 #include "ir/type.hpp"
 #include "sys/platform.hpp"
