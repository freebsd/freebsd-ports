--- bx/tests/math_test.cpp.orig	2024-01-03 18:10:08 UTC
+++ bx/tests/math_test.cpp
@@ -28,7 +28,7 @@ TEST_CASE("isFinite, isInfinite, isNan", "[math]")
 #else
 		REQUIRE(::isnanf(u.f)  == bx::isNan(u.f) );
 		REQUIRE(::finitef(u.f) == bx::isFinite(u.f) );
-		REQUIRE(::isinff(u.f)  == bx::isInfinite(u.f) );
+		REQUIRE(::isinf(u.f)  == bx::isInfinite(u.f) );
 #endif // BX_PLATFORM_OSX
 	}
 }
