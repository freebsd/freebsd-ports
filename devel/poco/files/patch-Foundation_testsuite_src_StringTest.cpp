Workaround for base GCC on 9.3-i386:
src/StringTest.cpp:929: error: integer constant is too large for 'long' type
--- Foundation/testsuite/src/StringTest.cpp.orig	2016-03-06 19:30:11 UTC
+++ Foundation/testsuite/src/StringTest.cpp
@@ -926,9 +926,9 @@ void StringTest::testIntToString()
 	assert (uIntToStr(0xF0F0F0F0, 2, result));
 	assert (result == "11110000111100001111000011110000");
 #if defined(POCO_HAVE_INT64)
-	assert (uIntToStr(0xFFFFFFFFFFFFFFFF, 2, result));
+	assert (uIntToStr(0xFFFFFFFFFFFFFFFFLL, 2, result));
 	assert (result == "1111111111111111111111111111111111111111111111111111111111111111");
-	assert (uIntToStr(0xFF00000FF00000FF, 2, result));
+	assert (uIntToStr(0xFF00000FF00000FFLL, 2, result));
 	assert (result == "1111111100000000000000000000111111110000000000000000000011111111");
 #endif
 
@@ -957,14 +957,14 @@ void StringTest::testIntToString()
 	assert (result == "0x499602D2");
 	assert (uIntToStr(1234567890, 0x10, result, true, 15, '0'));
 	assert (result == "0x00000499602D2");
-	assert (uIntToStr(0x1234567890ABCDEF, 0x10, result, true));
+	assert (uIntToStr(0x1234567890ABCDEFLL, 0x10, result, true));
 	assert (result == "0x1234567890ABCDEF");
 	assert (uIntToStr(0xDEADBEEF, 0x10, result));
 	assert (result == "DEADBEEF");
 #if defined(POCO_HAVE_INT64)
-	assert (uIntToStr(0xFFFFFFFFFFFFFFFF, 0x10, result));
+	assert (uIntToStr(0xFFFFFFFFFFFFFFFFLL, 0x10, result));
 	assert (result == "FFFFFFFFFFFFFFFF");
-	assert (uIntToStr(0xFFFFFFFFFFFFFFFF, 0x10, result, true));
+	assert (uIntToStr(0xFFFFFFFFFFFFFFFFLL, 0x10, result, true));
 	assert (result == "0xFFFFFFFFFFFFFFFF");
 #endif
 
