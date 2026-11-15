--- third_party/perfetto/src/base/string_utils.cc.orig	2026-10-19 21:50:55 UTC
+++ third_party/perfetto/src/base/string_utils.cc
@@ -40,7 +40,8 @@ double StrToD(const char* nptr, char** endptr) {
 // Locale-independent as possible version of strtod.
 double StrToD(const char* nptr, char** endptr) {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) ||           \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   static auto c_locale = newlocale(LC_ALL, "C", nullptr);
   return strtod_l(nptr, endptr, c_locale);
