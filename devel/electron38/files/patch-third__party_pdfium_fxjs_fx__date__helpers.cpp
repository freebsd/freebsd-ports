--- third_party/pdfium/fxjs/fx_date_helpers.cpp.orig	2025-06-30 07:04:30 UTC
+++ third_party/pdfium/fxjs/fx_date_helpers.cpp
@@ -41,6 +41,11 @@ double GetLocalTZA() {
   }
   time_t t = 0;
   FXSYS_time(&t);
+#ifdef __FreeBSD__
+  struct tm lt;
+  localtime_r(&t, &lt);
+  return (double)(-(lt.tm_gmtoff * 1000));
+#else
   FXSYS_localtime(&t);
 #if BUILDFLAG(IS_WIN)
   // In gcc 'timezone' is a global variable declared in time.h. In VC++, that
@@ -49,6 +54,7 @@ double GetLocalTZA() {
   _get_timezone(&timezone);
 #endif
   return (double)(-(timezone * 1000));
+#endif // __FreeBSD__
 }
 
 int GetDaylightSavingTA(double d) {
