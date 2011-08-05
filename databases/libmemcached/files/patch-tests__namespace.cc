--- tests/namespace.cc.orig	2011-08-05 09:20:13.000000000 +0800
+++ tests/namespace.cc	2011-08-05 09:21:03.000000000 +0800
@@ -58,13 +58,13 @@ test_return_t memcached_increment_namesp
                memcached_increment(memc,
                                    test_literal_param("number"),
                                    1, &new_number));
-  test_compare(1UL, new_number);
+  test_compare(1UL, (unsigned long)new_number);
 
   test_compare(MEMCACHED_SUCCESS, 
                memcached_increment(memc,
                                    test_literal_param("number"),
                                    1, &new_number));
-  test_compare(2UL, new_number);
+  test_compare(2UL, (unsigned long)new_number);
 
   memcached_st *clone= memcached_clone(NULL, memc);
 
@@ -86,7 +86,7 @@ test_return_t memcached_increment_namesp
                              test_literal_param("number"),
                              0, 0, 0);
   test_true(value);
-  test_compare(2UL, strlen(value));
+  test_compare(2UL, (unsigned long)strlen(value));
   test_strcmp("10", value);
   free(value);
 
@@ -94,13 +94,13 @@ test_return_t memcached_increment_namesp
                memcached_increment(clone,
                                    test_literal_param("number"),
                                    1, &new_number));
-  test_compare(11UL, new_number);
+  test_compare(11UL, (unsigned long)new_number);
 
   test_compare(MEMCACHED_SUCCESS, 
                memcached_increment(memc,
                                    test_literal_param("number"),
                                    1, &new_number));
-  test_compare(3UL, new_number);
+  test_compare(3UL, (unsigned long)new_number);
 
   memcached_free(clone);
 
