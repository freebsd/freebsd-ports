--- backend/src/ir/immediate.hpp.orig	2017-01-20 10:40:51 UTC
+++ backend/src/ir/immediate.hpp
@@ -25,6 +25,7 @@
 #ifndef __GBE_IR_IMMEDIATE_HPP__
 #define __GBE_IR_IMMEDIATE_HPP__
 
+#include <cmath>
 #include <string.h>
 #include "ir/type.hpp"
 #include "ir/half.hpp"
