--- test/FloatToInt.cpp.orig	2013-02-11 17:23:26 UTC
+++ test/FloatToInt.cpp
@@ -115,7 +115,7 @@ TEST_F(FloatToIntTest, Int16)
 		EXPECT_EQ(readData[i], expectedData[i]);
 }
 
-static const int32_t kMinInt24 = -1<<23;
+static const int32_t kMinInt24 = ~0u<<23;
 static const int32_t kMaxInt24 = (1<<23) - 1;
 
 TEST_F(FloatToIntTest, Int24)
