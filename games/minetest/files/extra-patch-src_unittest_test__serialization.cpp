--- src/unittest/test_serialization.cpp.orig	2016-05-15 12:49:15 UTC
+++ src/unittest/test_serialization.cpp
@@ -295,7 +295,7 @@ void TestSerialization::testStreamRead()
 	UASSERT(readU8(is) == 0x11);
 	UASSERT(readU16(is) == 0x2233);
 	UASSERT(readU32(is) == 0x44556677);
-	UASSERT(readU64(is) == 0x8899AABBCCDDEEFF);
+	UASSERT(readU64(is) == 0x8899AABBCCDDEEFFULL);
 
 	UASSERT(readS8(is) == -128);
 	UASSERT(readS16(is) == 30000);
@@ -336,7 +336,7 @@ void TestSerialization::testStreamWrite(
 	writeU8(os, 0x11);
 	writeU16(os, 0x2233);
 	writeU32(os, 0x44556677);
-	writeU64(os, 0x8899AABBCCDDEEFF);
+	writeU64(os, 0x8899AABBCCDDEEFFULL);
 
 	writeS8(os, -128);
 	writeS16(os, 30000);
@@ -382,7 +382,7 @@ void TestSerialization::testVecPut()
 	putU8(&buf, 0x11);
 	putU16(&buf, 0x2233);
 	putU32(&buf, 0x44556677);
-	putU64(&buf, 0x8899AABBCCDDEEFF);
+	putU64(&buf, 0x8899AABBCCDDEEFFULL);
 
 	putS8(&buf, -128);
 	putS16(&buf, 30000);
@@ -464,7 +464,7 @@ void TestSerialization::testBufReader()
 	UASSERT(buf.getU8() == 0x11);
 	UASSERT(buf.getU16() == 0x2233);
 	UASSERT(buf.getU32() == 0x44556677);
-	UASSERT(buf.getU64() == 0x8899AABBCCDDEEFF);
+	UASSERT(buf.getU64() == 0x8899AABBCCDDEEFFULL);
 	UASSERT(buf.getS8() == -128);
 	UASSERT(buf.getS16() == 30000);
 	UASSERT(buf.getS32() == -6);
@@ -576,7 +576,7 @@ void TestSerialization::testBufReader()
 	UASSERT(u8_data == 0x11);
 	UASSERT(u16_data == 0x2233);
 	UASSERT(u32_data == 0x44556677);
-	UASSERT(u64_data == 0x8899AABBCCDDEEFF);
+	UASSERT(u64_data == 0x8899AABBCCDDEEFFULL);
 	UASSERT(s8_data == -128);
 	UASSERT(s16_data == 30000);
 	UASSERT(s32_data == -6);
