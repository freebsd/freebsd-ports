--- tests/plus.cpp.orig	2011-08-05 09:23:49.000000000 +0800
+++ tests/plus.cpp	2011-08-05 09:25:22.000000000 +0800
@@ -128,13 +128,13 @@ test_return_t increment_test(memcached_s
   test_compare(int_inc_value, int_ret_value);
 
   test_true(mcach.increment(key, 1, &int_ret_value));
-  test_compare(2UL, int_ret_value);
+  test_compare(2UL, (unsigned long)int_ret_value);
 
   test_true(mcach.increment(key, 1, &int_ret_value));
-  test_compare(3UL, int_ret_value);
+  test_compare(3UL, (unsigned long)int_ret_value);
 
   test_true(mcach.increment(key, 5, &int_ret_value));
-  test_compare(8UL, int_ret_value);
+  test_compare(8UL, (unsigned long)int_ret_value);
 
   return TEST_SUCCESS;
 }
