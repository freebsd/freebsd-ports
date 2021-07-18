--- base/test/test_suite.cc.orig	2021-01-07 00:36:18 UTC
+++ base/test/test_suite.cc
@@ -66,7 +66,7 @@
 #include "base/test/test_support_android.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/test/fontconfig_util_linux.h"
 #endif
 
@@ -382,14 +382,14 @@ void TestSuite::PreInitialize() {
   testing::GTEST_FLAG(catch_exceptions) = false;
 #endif
   EnableTerminationOnHeapCorruption();
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_AURA)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_AURA)
   // When calling native char conversion functions (e.g wrctomb) we need to
   // have the locale set. In the absence of such a call the "C" locale is the
   // default. In the gtk code (below) gtk_init() implicitly sets a locale.
   setlocale(LC_ALL, "");
   // We still need number to string conversions to be locale insensitive.
   setlocale(LC_NUMERIC, "C");
-#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_AURA)
+#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_AURA)
 
   // On Android, AtExitManager is created in
   // testing/android/native_test_wrapper.cc before main() is called.
@@ -650,7 +650,7 @@ void TestSuite::Initialize() {
   // TODO(jshin): Should we set the locale via an OS X locale API here?
   i18n::SetICUDefaultLocale("en_US");
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   SetUpFontconfig();
 #endif
 
