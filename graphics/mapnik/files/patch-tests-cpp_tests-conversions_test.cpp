--- tests/cpp_tests/conversions_test.cpp.orig	2013-06-30 22:35:29.000000000 +0400
+++ tests/cpp_tests/conversions_test.cpp	2013-06-30 22:38:32.000000000 +0400
@@ -166,31 +166,31 @@
         BOOST_TEST_EQ( out,  "1e+09" );
         out.clear();
 
-        to_string(out, double(10000000000));
+        to_string(out, double(10000000000ULL));
         BOOST_TEST_EQ( out,  "1e+10" );
         out.clear();
 
-        to_string(out, double(100000000000));
+        to_string(out, double(100000000000ULL));
         BOOST_TEST_EQ( out,  "1e+11" );
         out.clear();
 
-        to_string(out, double(1000000000000));
+        to_string(out, double(1000000000000ULL));
         BOOST_TEST_EQ( out,  "1e+12" );
         out.clear();
 
-        to_string(out, double(10000000000000));
+        to_string(out, double(10000000000000ULL));
         BOOST_TEST_EQ( out,  "1e+13" );
         out.clear();
 
-        to_string(out, double(100000000000000));
+        to_string(out, double(100000000000000ULL));
         BOOST_TEST_EQ( out,  "1e+14" );
         out.clear();
 
-        to_string(out, double(1000000000000005));
+        to_string(out, double(1000000000000005ULL));
         BOOST_TEST_EQ( out,  "1e+15" );
         out.clear();
 
-        to_string(out, double(-1000000000000000));
+        to_string(out, double(-1000000000000000LL));
         BOOST_TEST_EQ( out,  "-1e+15" );
         out.clear();
 
@@ -210,7 +210,7 @@
         BOOST_TEST_EQ( out,  "67.35" );
         out.clear();
 
-        to_string(out, double(1234000000000000));
+        to_string(out, double(1234000000000000ULL));
         BOOST_TEST_EQ( out,  "1.234e+15" );
         out.clear();
 
@@ -235,16 +235,16 @@
         BOOST_TEST_EQ( out, "-2" );
         out.clear();
 
-        to_string(out, int(2147483647));
+        to_string(out, int(2147483647ULL));
         BOOST_TEST_EQ( out, "2147483647" );
         out.clear();
 
-        to_string(out, int(-2147483648));
+        to_string(out, int(-2147483648LL));
         BOOST_TEST_EQ( out, "-2147483648" );
         out.clear();
 
         // unsigned
-        to_string(out, unsigned(4294967295));
+        to_string(out, unsigned(4294967295ULL));
         BOOST_TEST_EQ( out, "4294967295" );
         out.clear();
 
@@ -258,7 +258,7 @@
         BOOST_TEST_EQ( out, "-2" );
         out.clear();
 
-        to_string(out,mapnik::value_integer(9223372036854775807));
+        to_string(out,mapnik::value_integer(9223372036854775807ULL));
         BOOST_TEST_EQ( out, "9223372036854775807" );
         out.clear();
 #else
