--- src/tests/test_util.cpp.orig	2015-06-25 23:08:11 UTC
+++ src/tests/test_util.cpp
@@ -89,7 +89,7 @@ BOOST_AUTO_TEST_CASE( test_count_leading
 	BOOST_CHECK( count_leading_ones(static_cast<boost::uint8_t>(0xFF)) == 8 );
 	BOOST_CHECK( count_leading_ones(static_cast<boost::uint16_t>(0xFFFF)) == 16 );
 	BOOST_CHECK( count_leading_ones(static_cast<boost::uint32_t>(0xFFFFFFFF)) == 32 );
-	BOOST_CHECK( count_leading_ones(static_cast<boost::uint64_t>(0xFFFFFFFFFFFFFFFF))
+	BOOST_CHECK( count_leading_ones(static_cast<boost::uint64_t>(0xFFFFFFFFFFFFFFFFULL))
 		== 64 );
 	BOOST_CHECK( count_leading_ones(static_cast<boost::uint8_t>(0xF8)) == 5 );
 	BOOST_CHECK( count_leading_ones(static_cast<boost::uint16_t>(54321)) == 2 );
