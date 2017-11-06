FreeBSD 10.3 lacks __cxa_thread_atexit, so revert
https://github.com/sekrit-twc/zimg/commit/7e47d8d2a892

--- src/zimg/api/zimg.cpp.orig	2017-01-21 18:59:03 UTC
+++ src/zimg/api/zimg.cpp
@@ -1,6 +1,5 @@
 #include <cmath>
 #include <memory>
-#include <string>
 #include <tuple>
 #include <type_traits>
 #include <utility>
@@ -31,7 +30,7 @@ constexpr unsigned API_VERSION_2_2 = ZIM
 #define STRIDE_ALIGNMENT_ASSERT(x) zassert_d(!(x) || (x) % zimg::ALIGNMENT == 0, "buffer stride not aligned")
 
 thread_local zimg_error_code_e g_last_error = ZIMG_ERROR_SUCCESS;
-thread_local std::string g_last_error_msg;
+thread_local char g_last_error_msg[1024];
 
 constexpr unsigned VERSION_INFO[] = { 2, 4, 0 };
 
@@ -43,19 +42,10 @@ T *assert_dynamic_type(U *ptr) noexcept
 	return static_cast<T *>(ptr);
 }
 
-void clear_last_error_message() noexcept
-{
-	g_last_error_msg.clear();
-	g_last_error_msg.shrink_to_fit();
-}
-
 void record_exception_message(const zimg::error::Exception &e) noexcept
 {
-	try {
-		g_last_error_msg = e.what();
-	} catch (const std::bad_alloc &) {
-		clear_last_error_message();
-	}
+	strncpy(g_last_error_msg, e.what(), sizeof(g_last_error_msg) - 1);
+	g_last_error_msg[sizeof(g_last_error_msg) - 1] = '\0';
 }
 
 zimg_error_code_e handle_exception(std::exception_ptr eptr) noexcept
@@ -438,7 +428,7 @@ unsigned zimg_get_api_version(unsigned *
 zimg_error_code_e zimg_get_last_error(char *err_msg, size_t n)
 {
 	if (err_msg && n) {
-		std::strncpy(err_msg, g_last_error_msg.c_str(), n);
+		strncpy(err_msg, g_last_error_msg, n);
 		err_msg[n - 1] = '\0';
 	}
 
@@ -447,8 +437,8 @@ zimg_error_code_e zimg_get_last_error(ch
 
 void zimg_clear_last_error(void)
 {
+	g_last_error_msg[0] = '\0';
 	g_last_error = ZIMG_ERROR_SUCCESS;
-	clear_last_error_message();
 }
 
 unsigned zimg_select_buffer_mask(unsigned count)
