--- src/test/InputProcessorTest.cpp.orig	2019-09-01 12:33:22 UTC
+++ src/test/InputProcessorTest.cpp
@@ -82,7 +82,7 @@ BOOST_AUTO_TEST_CASE(isHetTest) {
 	BOOST_REQUIRE_EQUAL(inputProc.isHet('A','?'), false);
 	BOOST_REQUIRE_EQUAL(inputProc.isHet('A','.'), false);
 	BOOST_REQUIRE_EQUAL(inputProc.isHet('A',' '), false);
-	BOOST_REQUIRE_EQUAL(inputProc.isHet('C', NULL), true);
+	BOOST_REQUIRE_EQUAL(inputProc.isHet('C','\0'), true);
 }
 
 BOOST_AUTO_TEST_CASE(readAllelesTest) {
