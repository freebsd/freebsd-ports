--- rapid/plugin/x/mysqlxtest_src/mysqlxtest.cc.orig	2016-03-28 18:06:12 UTC
+++ rapid/plugin/x/mysqlxtest_src/mysqlxtest.cc
@@ -1661,7 +1661,8 @@ private:
     if (2 == argl.size())
       tolerance = atoi(argl[1].c_str());
 
-    if (abs(expected_msec - msec) > tolerance)
+#define my_abs_64(x) ((x) < 0 ? (-x) : (x))
+    if (my_abs_64((expected_msec - msec)) > tolerance)
     {
       std::cerr << "Timeout should occur after " << expected_msec << "ms, but it was " << msec <<"ms.  \n";
       return Stop_with_failure;
