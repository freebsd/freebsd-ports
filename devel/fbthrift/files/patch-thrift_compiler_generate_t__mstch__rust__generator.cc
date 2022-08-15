- https://github.com/facebook/fbthrift/issues/512

--- thrift/compiler/generate/t_mstch_rust_generator.cc.orig	2022-08-15 22:34:21 UTC
+++ thrift/compiler/generate/t_mstch_rust_generator.cc
@@ -16,6 +16,7 @@
 
 #include <cassert>
 #include <cctype>
+#include <fstream>
 #include <set>
 #include <stdexcept>
 #include <string>
