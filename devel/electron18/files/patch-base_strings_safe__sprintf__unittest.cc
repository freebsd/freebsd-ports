--- base/strings/safe_sprintf_unittest.cc.orig	2022-05-19 03:45:15 UTC
+++ base/strings/safe_sprintf_unittest.cc
@@ -731,6 +731,7 @@ TEST(SafeSPrintfTest, EmbeddedNul) {
 #endif
 }
 
+#if !BUILDFLAG(IS_BSD)
 TEST(SafeSPrintfTest, EmitNULL) {
   char buf[40];
 #if defined(__GNUC__)
@@ -747,6 +748,7 @@ TEST(SafeSPrintfTest, EmitNULL) {
 #pragma GCC diagnostic pop
 #endif
 }
+#endif
 
 TEST(SafeSPrintfTest, PointerSize) {
   // The internal data representation is a 64bit value, independent of the
