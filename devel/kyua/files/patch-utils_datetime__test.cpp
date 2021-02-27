--- utils/datetime_test.cpp.orig	2016-08-26 10:09:37 UTC
+++ utils/datetime_test.cpp
@@ -532,11 +532,11 @@ ATF_TEST_CASE_BODY(timestamp__subtractio
     ATF_REQUIRE_EQ(datetime::delta(100, 0), ts3 - ts1);
     ATF_REQUIRE_EQ(datetime::delta(99, 999988), ts3 - ts2);
 
-    ATF_REQUIRE_THROW_RE(
-        std::runtime_error,
-        "Cannot subtract 1291970850123456us from 1291970750123468us "
-        ".*negative datetime::delta.*not supported",
-        ts2 - ts3);
+    /*
+     * NOTE (ngie): behavior change for
+     * https://github.com/jmmv/kyua/issues/155 .
+     */
+    ATF_REQUIRE_EQ(datetime::delta::from_microseconds(1), ts2 - ts3);
 }
 
 
