--- boost/atomic/detail/cas128strong.hpp	2013-07-20 20:01:35.000000000 +0200
+++ boost/atomic/detail/cas128strong.hpp.orig	2014-04-03 16:34:19.000000000 +0200
@@ -196,15 +196,17 @@
 
 public:
     BOOST_DEFAULTED_FUNCTION(base_atomic(void), {})
-    explicit base_atomic(value_type const& v) BOOST_NOEXCEPT : v_(0)
+    explicit base_atomic(value_type const& v) BOOST_NOEXCEPT
     {
+        memset(&v_, 0, sizeof(v_));
         memcpy(&v_, &v, sizeof(value_type));
     }
 
     void
     store(value_type const& value, memory_order order = memory_order_seq_cst) volatile BOOST_NOEXCEPT
     {
-        storage_type value_s = 0;
+        storage_type value_s;
+        memset(&value_s, 0, sizeof(value_s));
         memcpy(&value_s, &value, sizeof(value_type));
         platform_fence_before_store(order);
         platform_store128(value_s, &v_);
@@ -247,7 +249,9 @@
         memory_order success_order,
         memory_order failure_order) volatile BOOST_NOEXCEPT
     {
-        storage_type expected_s = 0, desired_s = 0;
+        storage_type expected_s, desired_s;
+        memset(&expected_s, 0, sizeof(expected_s));
+        memset(&desired_s, 0, sizeof(desired_s));
         memcpy(&expected_s, &expected, sizeof(value_type));
         memcpy(&desired_s, &desired, sizeof(value_type));
 
