--- base/time/time_unittest.cc.orig	2021-07-15 19:13:30 UTC
+++ base/time/time_unittest.cc
@@ -2074,6 +2074,7 @@ TEST(TimeDelta, Overflows) {
   EXPECT_TRUE((kLargeDelta / 0.5).is_max());
   EXPECT_TRUE((kLargeDelta / -0.5).is_min());
 
+#if !defined(OS_BSD)
   static_assert(
       TimeDelta::Max() / kOneSecond == std::numeric_limits<double>::infinity(),
       "");
@@ -2102,6 +2103,7 @@ TEST(TimeDelta, Overflows) {
   static_assert(TimeDelta::Max() % -kOneSecond == TimeDelta::Max(), "");
   static_assert(TimeDelta::Min() % kOneSecond == TimeDelta::Min(), "");
   static_assert(TimeDelta::Min() % -kOneSecond == TimeDelta::Min(), "");
+#endif
 
   // Division by zero.
   static_assert((kOneSecond / 0).is_max(), "");
