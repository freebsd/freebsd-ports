Building tests with gcc-15 fails with:

operators_unary.cpp: In function 'int main()':
operators_unary.cpp:30:14: error: 'uint32_t' was not declared in this scope
   30 |         term<uint32_t> x{{2u}};
      |              ^~~~~~~~

Bug: https://bugs.gentoo.org/954810

--- libs/yap/test/operators_unary.cpp.orig	2025-08-06 18:49:15 UTC
+++ libs/yap/test/operators_unary.cpp
@@ -8,7 +8,7 @@
 #include <boost/core/lightweight_test.hpp>
 
 #include <sstream>
-
+#include <cstdint>
 
 template<typename T>
 using term = boost::yap::terminal<boost::yap::expression, T>;
