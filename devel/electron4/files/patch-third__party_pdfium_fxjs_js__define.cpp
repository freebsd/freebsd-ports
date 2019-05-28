--- third_party/pdfium/fxjs/js_define.cpp.orig	2019-03-15 06:41:33 UTC
+++ third_party/pdfium/fxjs/js_define.cpp
@@ -23,6 +23,11 @@ double GetLocalTZA() {
     return 0;
   time_t t = 0;
   time(&t);
+#ifdef __FreeBSD__
+  struct tm lt;
+  localtime_r(&t, &lt);
+  return (double)(-(lt.tm_gmtoff * 1000));
+#else
   localtime(&t);
 #if _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
   // In gcc 'timezone' is a global variable declared in time.h. In VC++, that
@@ -31,6 +36,7 @@ double GetLocalTZA() {
   _get_timezone(&timezone);
 #endif  // _FX_PLATFORM_ == _FX_PLATFORM_WINDOWS_
   return (double)(-(timezone * 1000));
+#endif // __FreeBSD__
 }
 
 int GetDaylightSavingTA(double d) {
