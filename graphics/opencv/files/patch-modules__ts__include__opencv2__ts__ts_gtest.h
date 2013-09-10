--- ./modules/ts/include/opencv2/ts/ts_gtest.h.orig	2013-09-01 01:03:57.000000000 +0100
+++ ./modules/ts/include/opencv2/ts/ts_gtest.h	2013-09-01 01:03:38.000000000 +0100
@@ -53,6 +53,7 @@
 
 #include <limits>
 #include <vector>
+#include <unistd.h>
 
 // Copyright 2005, Google Inc.
 // All rights reserved.
@@ -543,7 +544,7 @@
 // Author: wan@google.com (Zhanyong Wan)
 
 // Implements a subset of TR1 tuple needed by Google Test and Google Mock.
-
+#define GTEST_INCLUDE_GTEST_INTERNAL_GTEST_TUPLE_H_ 1
 #ifndef GTEST_INCLUDE_GTEST_INTERNAL_GTEST_TUPLE_H_
 #define GTEST_INCLUDE_GTEST_INTERNAL_GTEST_TUPLE_H_
 
@@ -1504,11 +1505,31 @@
 // <tr1/functional>.  Hence the following #define is a hack to prevent
 // <tr1/functional> from being included.
 #define _TR1_FUNCTIONAL 1
+#if __has_include(<tuple>)
+#include <tuple>
+namespace gtest {
+	using ::std::tuple;
+}
+#else
 #include <tr1/tuple>
+namespace gtest {
+	using ::std::tr1::tuple;
+}
+#endif
 #undef _TR1_FUNCTIONAL  // Allows the user to #include
                         // <tr1/functional> if he chooses to.
 #else
-#include <tr1/tuple>  // NOLINT
+#if __has_include(<tuple>)
+#include <tuple>
+namespace gtest {
+	using ::std::tuple;
+}
+#else
+#include <tr1/tuple>
+namespace gtest {
+	using ::std::tr1::tuple;
+}
+#endif
 #endif  // !GTEST_HAS_RTTI && GTEST_GCC_VER_ < 40302
 
 #else
@@ -11951,9 +11972,9 @@
 //
 template <typename T1, typename T2>
 class CartesianProductGenerator2
-    : public ParamGeneratorInterface< ::std::tr1::tuple<T1, T2> > {
+    : public ParamGeneratorInterface< gtest::tuple<T1, T2> > {
  public:
-  typedef ::std::tr1::tuple<T1, T2> ParamType;
+  typedef gtest::tuple<T1, T2> ParamType;
 
   CartesianProductGenerator2(const ParamGenerator<T1>& g1,
       const ParamGenerator<T2>& g2)
@@ -12066,9 +12087,9 @@
 
 template <typename T1, typename T2, typename T3>
 class CartesianProductGenerator3
-    : public ParamGeneratorInterface< ::std::tr1::tuple<T1, T2, T3> > {
+    : public ParamGeneratorInterface< gtest::tuple<T1, T2, T3> > {
  public:
-  typedef ::std::tr1::tuple<T1, T2, T3> ParamType;
+  typedef gtest::tuple<T1, T2, T3> ParamType;
 
   CartesianProductGenerator3(const ParamGenerator<T1>& g1,
       const ParamGenerator<T2>& g2, const ParamGenerator<T3>& g3)
@@ -12198,9 +12219,9 @@
 
 template <typename T1, typename T2, typename T3, typename T4>
 class CartesianProductGenerator4
-    : public ParamGeneratorInterface< ::std::tr1::tuple<T1, T2, T3, T4> > {
+    : public ParamGeneratorInterface< gtest::tuple<T1, T2, T3, T4> > {
  public:
-  typedef ::std::tr1::tuple<T1, T2, T3, T4> ParamType;
+  typedef gtest::tuple<T1, T2, T3, T4> ParamType;
 
   CartesianProductGenerator4(const ParamGenerator<T1>& g1,
       const ParamGenerator<T2>& g2, const ParamGenerator<T3>& g3,
@@ -12349,9 +12370,9 @@
 
 template <typename T1, typename T2, typename T3, typename T4, typename T5>
 class CartesianProductGenerator5
-    : public ParamGeneratorInterface< ::std::tr1::tuple<T1, T2, T3, T4, T5> > {
+    : public ParamGeneratorInterface< gtest::tuple<T1, T2, T3, T4, T5> > {
  public:
-  typedef ::std::tr1::tuple<T1, T2, T3, T4, T5> ParamType;
+  typedef gtest::tuple<T1, T2, T3, T4, T5> ParamType;
 
   CartesianProductGenerator5(const ParamGenerator<T1>& g1,
       const ParamGenerator<T2>& g2, const ParamGenerator<T3>& g3,
@@ -12517,10 +12538,10 @@
 template <typename T1, typename T2, typename T3, typename T4, typename T5,
     typename T6>
 class CartesianProductGenerator6
-    : public ParamGeneratorInterface< ::std::tr1::tuple<T1, T2, T3, T4, T5,
+    : public ParamGeneratorInterface< gtest::tuple<T1, T2, T3, T4, T5,
         T6> > {
  public:
-  typedef ::std::tr1::tuple<T1, T2, T3, T4, T5, T6> ParamType;
+  typedef gtest::tuple<T1, T2, T3, T4, T5, T6> ParamType;
 
   CartesianProductGenerator6(const ParamGenerator<T1>& g1,
       const ParamGenerator<T2>& g2, const ParamGenerator<T3>& g3,
@@ -12703,10 +12724,10 @@
 template <typename T1, typename T2, typename T3, typename T4, typename T5,
     typename T6, typename T7>
 class CartesianProductGenerator7
-    : public ParamGeneratorInterface< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6,
+    : public ParamGeneratorInterface< gtest::tuple<T1, T2, T3, T4, T5, T6,
         T7> > {
  public:
-  typedef ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7> ParamType;
+  typedef gtest::tuple<T1, T2, T3, T4, T5, T6, T7> ParamType;
 
   CartesianProductGenerator7(const ParamGenerator<T1>& g1,
       const ParamGenerator<T2>& g2, const ParamGenerator<T3>& g3,
@@ -12906,10 +12927,10 @@
 template <typename T1, typename T2, typename T3, typename T4, typename T5,
     typename T6, typename T7, typename T8>
 class CartesianProductGenerator8
-    : public ParamGeneratorInterface< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6,
+    : public ParamGeneratorInterface< gtest::tuple<T1, T2, T3, T4, T5, T6,
         T7, T8> > {
  public:
-  typedef ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7, T8> ParamType;
+  typedef gtest::tuple<T1, T2, T3, T4, T5, T6, T7, T8> ParamType;
 
   CartesianProductGenerator8(const ParamGenerator<T1>& g1,
       const ParamGenerator<T2>& g2, const ParamGenerator<T3>& g3,
@@ -13128,10 +13149,10 @@
 template <typename T1, typename T2, typename T3, typename T4, typename T5,
     typename T6, typename T7, typename T8, typename T9>
 class CartesianProductGenerator9
-    : public ParamGeneratorInterface< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6,
+    : public ParamGeneratorInterface< gtest::tuple<T1, T2, T3, T4, T5, T6,
         T7, T8, T9> > {
  public:
-  typedef ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> ParamType;
+  typedef gtest::tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> ParamType;
 
   CartesianProductGenerator9(const ParamGenerator<T1>& g1,
       const ParamGenerator<T2>& g2, const ParamGenerator<T3>& g3,
@@ -13367,10 +13388,10 @@
 template <typename T1, typename T2, typename T3, typename T4, typename T5,
     typename T6, typename T7, typename T8, typename T9, typename T10>
 class CartesianProductGenerator10
-    : public ParamGeneratorInterface< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6,
+    : public ParamGeneratorInterface< gtest::tuple<T1, T2, T3, T4, T5, T6,
         T7, T8, T9, T10> > {
  public:
-  typedef ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> ParamType;
+  typedef gtest::tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> ParamType;
 
   CartesianProductGenerator10(const ParamGenerator<T1>& g1,
       const ParamGenerator<T2>& g2, const ParamGenerator<T3>& g3,
@@ -13632,8 +13653,8 @@
 CartesianProductHolder2(const Generator1& g1, const Generator2& g2)
       : g1_(g1), g2_(g2) {}
   template <typename T1, typename T2>
-  operator ParamGenerator< ::std::tr1::tuple<T1, T2> >() const {
-    return ParamGenerator< ::std::tr1::tuple<T1, T2> >(
+  operator ParamGenerator< gtest::tuple<T1, T2> >() const {
+    return ParamGenerator< gtest::tuple<T1, T2> >(
         new CartesianProductGenerator2<T1, T2>(
         static_cast<ParamGenerator<T1> >(g1_),
         static_cast<ParamGenerator<T2> >(g2_)));
@@ -13654,8 +13675,8 @@
     const Generator3& g3)
       : g1_(g1), g2_(g2), g3_(g3) {}
   template <typename T1, typename T2, typename T3>
-  operator ParamGenerator< ::std::tr1::tuple<T1, T2, T3> >() const {
-    return ParamGenerator< ::std::tr1::tuple<T1, T2, T3> >(
+  operator ParamGenerator< gtest::tuple<T1, T2, T3> >() const {
+    return ParamGenerator< gtest::tuple<T1, T2, T3> >(
         new CartesianProductGenerator3<T1, T2, T3>(
         static_cast<ParamGenerator<T1> >(g1_),
         static_cast<ParamGenerator<T2> >(g2_),
@@ -13679,8 +13700,8 @@
     const Generator3& g3, const Generator4& g4)
       : g1_(g1), g2_(g2), g3_(g3), g4_(g4) {}
   template <typename T1, typename T2, typename T3, typename T4>
-  operator ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4> >() const {
-    return ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4> >(
+  operator ParamGenerator< gtest::tuple<T1, T2, T3, T4> >() const {
+    return ParamGenerator< gtest::tuple<T1, T2, T3, T4> >(
         new CartesianProductGenerator4<T1, T2, T3, T4>(
         static_cast<ParamGenerator<T1> >(g1_),
         static_cast<ParamGenerator<T2> >(g2_),
@@ -13706,8 +13727,8 @@
     const Generator3& g3, const Generator4& g4, const Generator5& g5)
       : g1_(g1), g2_(g2), g3_(g3), g4_(g4), g5_(g5) {}
   template <typename T1, typename T2, typename T3, typename T4, typename T5>
-  operator ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5> >() const {
-    return ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5> >(
+  operator ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5> >() const {
+    return ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5> >(
         new CartesianProductGenerator5<T1, T2, T3, T4, T5>(
         static_cast<ParamGenerator<T1> >(g1_),
         static_cast<ParamGenerator<T2> >(g2_),
@@ -13737,8 +13758,8 @@
       : g1_(g1), g2_(g2), g3_(g3), g4_(g4), g5_(g5), g6_(g6) {}
   template <typename T1, typename T2, typename T3, typename T4, typename T5,
       typename T6>
-  operator ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6> >() const {
-    return ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6> >(
+  operator ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6> >() const {
+    return ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6> >(
         new CartesianProductGenerator6<T1, T2, T3, T4, T5, T6>(
         static_cast<ParamGenerator<T1> >(g1_),
         static_cast<ParamGenerator<T2> >(g2_),
@@ -13770,9 +13791,9 @@
       : g1_(g1), g2_(g2), g3_(g3), g4_(g4), g5_(g5), g6_(g6), g7_(g7) {}
   template <typename T1, typename T2, typename T3, typename T4, typename T5,
       typename T6, typename T7>
-  operator ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6,
+  operator ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6,
       T7> >() const {
-    return ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7> >(
+    return ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6, T7> >(
         new CartesianProductGenerator7<T1, T2, T3, T4, T5, T6, T7>(
         static_cast<ParamGenerator<T1> >(g1_),
         static_cast<ParamGenerator<T2> >(g2_),
@@ -13808,9 +13829,9 @@
           g8_(g8) {}
   template <typename T1, typename T2, typename T3, typename T4, typename T5,
       typename T6, typename T7, typename T8>
-  operator ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7,
+  operator ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6, T7,
       T8> >() const {
-    return ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7, T8> >(
+    return ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6, T7, T8> >(
         new CartesianProductGenerator8<T1, T2, T3, T4, T5, T6, T7, T8>(
         static_cast<ParamGenerator<T1> >(g1_),
         static_cast<ParamGenerator<T2> >(g2_),
@@ -13849,9 +13870,9 @@
           g9_(g9) {}
   template <typename T1, typename T2, typename T3, typename T4, typename T5,
       typename T6, typename T7, typename T8, typename T9>
-  operator ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7, T8,
+  operator ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6, T7, T8,
       T9> >() const {
-    return ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7, T8,
+    return ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6, T7, T8,
         T9> >(
         new CartesianProductGenerator9<T1, T2, T3, T4, T5, T6, T7, T8, T9>(
         static_cast<ParamGenerator<T1> >(g1_),
@@ -13893,9 +13914,9 @@
           g9_(g9), g10_(g10) {}
   template <typename T1, typename T2, typename T3, typename T4, typename T5,
       typename T6, typename T7, typename T8, typename T9, typename T10>
-  operator ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7, T8,
+  operator ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6, T7, T8,
       T9, T10> >() const {
-    return ParamGenerator< ::std::tr1::tuple<T1, T2, T3, T4, T5, T6, T7, T8,
+    return ParamGenerator< gtest::tuple<T1, T2, T3, T4, T5, T6, T7, T8,
         T9, T10> >(
         new CartesianProductGenerator10<T1, T2, T3, T4, T5, T6, T7, T8, T9,
             T10>(
