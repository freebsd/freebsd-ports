--- third_party/perfetto/src/base/string_utils.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/perfetto/src/base/string_utils.cc
@@ -36,9 +36,10 @@ namespace base {
 
 // Locale-independant as possible version of strtod.
 double StrToD(const char* nptr, char** endptr) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   static auto c_locale = newlocale(LC_ALL, "C", nullptr);
   return strtod_l(nptr, endptr, c_locale);
 #else
