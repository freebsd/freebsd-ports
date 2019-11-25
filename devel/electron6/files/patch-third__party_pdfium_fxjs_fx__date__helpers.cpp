--- third_party/pdfium/fxjs/fx_date_helpers.cpp.orig	2019-09-10 11:17:33 UTC
+++ third_party/pdfium/fxjs/fx_date_helpers.cpp
@@ -35,6 +35,11 @@ double GetLocalTZA() {
     return 0;
   time_t t = 0;
   FXSYS_time(&t);
+#ifdef __FreeBSD__
+  struct tm lt;
+  localtime_r(&t, &lt);
+  return (double)(-(lt.tm_gmtoff * 1000));
+#else
   FXSYS_localtime(&t);
 #if defined(OS_WIN)
   // In gcc 'timezone' is a global variable declared in time.h. In VC++, that
@@ -43,6 +48,7 @@ double GetLocalTZA() {
   _get_timezone(&timezone);
 #endif
   return (double)(-(timezone * 1000));
+#endif // __FreeBSD__
 }
 
 int GetDaylightSavingTA(double d) {
