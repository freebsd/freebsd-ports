--- test/NeXT.cpp.orig	2013-02-11 17:23:26 UTC
+++ test/NeXT.cpp
@@ -37,7 +37,7 @@
 
 #include "TestUtilities.h"
 
-const char kDataUnspecifiedLength[] =
+const unsigned char kDataUnspecifiedLength[] =
 {
 	'.', 's', 'n', 'd',
 	0, 0, 0, 24, // offset of 24 bytes
@@ -57,7 +57,7 @@ const char kDataUnspecifiedLength[] =
 	0, 55
 };
 
-const char kDataTruncated[] =
+const unsigned char kDataTruncated[] =
 {
 	'.', 's', 'n', 'd',
 	0, 0, 0, 24, // offset of 24 bytes
@@ -152,7 +152,7 @@ TEST(NeXT, Truncated)
 	ASSERT_EQ(::unlink(testFileName.c_str()), 0);
 }
 
-const char kDataZeroChannels[] =
+const unsigned char kDataZeroChannels[] =
 {
 	'.', 's', 'n', 'd',
 	0, 0, 0, 24, // offset of 24 bytes
