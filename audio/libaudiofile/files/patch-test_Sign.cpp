--- test/Sign.cpp.orig	2013-02-11 17:23:26 UTC
+++ test/Sign.cpp
@@ -116,7 +116,7 @@ TEST_F(SignConversionTest, Int16)
 		EXPECT_EQ(readData[i], expectedData[i]);
 }
 
-static const int32_t kMinInt24 = -1<<23;
+static const int32_t kMinInt24 = ~0u<<23;
 static const int32_t kMaxInt24 = (1<<23) - 1;
 static const uint32_t kMaxUInt24 = (1<<24) - 1;
 
@@ -157,7 +157,7 @@ TEST_F(SignConversionTest, Int32)
 	AFframecount framesRead = afReadFrames(file, AF_DEFAULT_TRACK, readData, frameCount);
 	ASSERT_EQ(framesRead, frameCount);
 	afCloseFile(file);
-	const uint32_t expectedData[] = { 0, -kMinInt32, kMaxUInt32 };
+	const uint32_t expectedData[] = { 0, -static_cast<uint32_t>(kMinInt32), kMaxUInt32 };
 	for (int i=0; i<frameCount; i++)
 		EXPECT_EQ(readData[i], expectedData[i]);
 }
