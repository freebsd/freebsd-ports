--- src/features.rb.orig	2011-04-06 19:35:39.000000000 +0000
+++ src/features.rb	2015-01-22 16:40:53.000000000 +0000
@@ -813,7 +813,6 @@
 begin
    conftest = CONFTEST_C.dup
    class Object
-      remove_const('CONFTEST_C')
    end
 
    CONFTEST_C = 'conftest.cxx'
@@ -878,7 +877,6 @@
 
 ensure
    class Object
-      remove_const('CONFTEST_C')
    end
 
    CONFTEST_C = conftest
