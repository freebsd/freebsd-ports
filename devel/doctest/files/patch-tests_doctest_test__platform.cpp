--- tests/doctest/test_platform.cpp.orig	2026-07-06 21:58:29 UTC
+++ tests/doctest/test_platform.cpp
@@ -28,6 +28,12 @@ constexpr auto wasi = false;
 constexpr auto wasi = false;
 #endif // DOCTEST_PLATFORM_WASI
 
+#if defined(DOCTEST_PLATFORM_FREEBSD)
+constexpr auto freebsd = true;
+#else
+constexpr auto freebsd = false;
+#endif // DOCTEST_PLATFORM_FREEBSD
+
 // 'linux' is an established pre-precessor define
 #if defined(DOCTEST_PLATFORM_LINUX)
 constexpr auto linux_ = true;
@@ -42,6 +48,7 @@ TEST_CASE("Exactly one platform is detected") {
     CAPTURE(platform::iphone);
     CAPTURE(platform::windows);
     CAPTURE(platform::wasi);
+    CAPTURE(platform::freebsd);
     CAPTURE(platform::linux_);
 
     const auto detected = std::multiset<bool>{
@@ -49,6 +56,7 @@ TEST_CASE("Exactly one platform is detected") {
         platform::iphone,
         platform::windows,
         platform::wasi,
+        platform::freebsd,
         platform::linux_,
     };
 
@@ -68,5 +76,6 @@ TEST_CASE("Detected platform matches what build-system
     CHECK(platform::iphone == (cmake_system_name == "iOS"));
     CHECK(platform::windows == (cmake_system_name == "Windows"));
     CHECK(platform::wasi == (cmake_system_name == "Emscripten"));
+    CHECK(platform::freebsd == (cmake_system_name == "FreeBSD"));
     CHECK(platform::linux_ == (cmake_system_name == "Linux"));
 }
