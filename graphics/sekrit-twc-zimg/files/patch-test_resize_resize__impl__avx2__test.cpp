--- test/resize/resize_impl_avx2_test.cpp.orig	2016-05-08 20:08:38 UTC
+++ test/resize/resize_impl_avx2_test.cpp
@@ -9,6 +9,8 @@
 #include "gtest/gtest.h"
 #include "graph/filter_validator.h"
 
+#include <cmath> // NAN
+
 namespace {
 
 void test_case(const zimg::resize::Filter &filter, bool horizontal, unsigned src_w, unsigned src_h, unsigned dst_w, unsigned dst_h,
