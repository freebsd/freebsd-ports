--- tests/unit/src/test_weightedList.cpp.orig	2025-10-25 18:32:22 UTC
+++ tests/unit/src/test_weightedList.cpp
@@ -348,7 +348,7 @@ SCENARIO( "Obtaining a random value", "[WeightedList][
 			REQUIRE( list.empty() );
 			THEN( "an informative runtime exception is thrown" ) {
 				CHECK_THROWS_AS( list.Get(), std::runtime_error );
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #if CATCH_VERSION_MAJOR >= 3
 				CHECK_THROWS_WITH( list.Get(), Catch::Matchers::ContainsSubstring("empty weighted list") );
 #endif
