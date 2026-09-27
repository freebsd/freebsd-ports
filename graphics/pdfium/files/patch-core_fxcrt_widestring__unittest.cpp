-- FreeBSD's vswprintf() requires a UTF-8 locale to format non-ASCII wide
-- characters. Switch to C.UTF-8 for those test assertions only.
--- core/fxcrt/widestring_unittest.cpp.orig	2026-09-24 10:57:02 UTC
+++ core/fxcrt/widestring_unittest.cpp
@@ -17,6 +17,7 @@
 #include "core/fxcrt/span.h"
 #include "core/fxcrt/utf16.h"
 #include "testing/gtest/include/gtest/gtest.h"
+#include "testing/scoped_locale.h"
 
 namespace fxcrt {
 namespace {
@@ -1947,6 +1948,11 @@ TEST(WideString, FormatString) {
   EXPECT_EQ(L"\u043e\u043f", WideString(L"\u043e\u043f"));
 
 #if !BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_BSD)
+  // FreeBSD's vswprintf() needs a UTF-8 locale to format non-ASCII wide
+  // characters; restore the previous locale when leaving this scope.
+  pdfium::ScopedLocale locale("C.UTF-8");
+#endif
   // See https://bugs.chromium.org/p/pdfium/issues/detail?id=1132
   EXPECT_EQ(L"\u043e\u043f", WideString::Format(L"\u043e\u043f"));
   EXPECT_EQ(L"\u043e\u043f", WideString::Format(L"%ls", L"\u043e\u043f"));
