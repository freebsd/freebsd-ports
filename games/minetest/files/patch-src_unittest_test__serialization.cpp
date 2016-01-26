--- src/unittest/test_serialization.cpp.orig	2015-08-20 02:02:00 UTC
+++ src/unittest/test_serialization.cpp
@@ -289,7 +289,7 @@ void TestSerialization::testStreamRead()
 	UASSERT(readU8(is) == 0x11);
 	UASSERT(readU16(is) == 0x2233);
 	UASSERT(readU32(is) == 0x44556677);
-	UASSERT(readU64(is) == 0x8899AABBCCDDEEFF);
+	UASSERT(readU64(is) == 0x8899AABBCCDDEEFFULL);
 
 	UASSERT(readS8(is) == -128);
 	UASSERT(readS16(is) == 30000);
@@ -330,7 +330,7 @@ void TestSerialization::testStreamWrite(
 	writeU8(os, 0x11);
 	writeU16(os, 0x2233);
 	writeU32(os, 0x44556677);
-	writeU64(os, 0x8899AABBCCDDEEFF);
+	writeU64(os, 0x8899AABBCCDDEEFFULL);
 
 	writeS8(os, -128);
 	writeS16(os, 30000);
