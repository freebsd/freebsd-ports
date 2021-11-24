--- third_party/pdfium/xfa/fxfa/parser/cxfa_timezoneprovider.cpp.orig	2021-07-15 19:15:51 UTC
+++ third_party/pdfium/xfa/fxfa/parser/cxfa_timezoneprovider.cpp
@@ -6,12 +6,16 @@
 
 #include "xfa/fxfa/parser/cxfa_timezoneprovider.h"
 
+#include <stdint.h>
 #include <stdlib.h>
 #include <time.h>
 
 #include "build/build_config.h"
 
 static bool g_bProviderTimeZoneSet = false;
+#if defined(OS_BSD)
+static long g_lTimeZoneOffset = 0;
+#endif
 
 #if defined(OS_WIN)
 #define TIMEZONE _timezone
@@ -24,9 +28,21 @@ static bool g_bProviderTimeZoneSet = false;
 CXFA_TimeZoneProvider::CXFA_TimeZoneProvider() {
   if (!g_bProviderTimeZoneSet) {
     g_bProviderTimeZoneSet = true;
+#if defined(OS_BSD)
+    time_t now = time(nullptr);
+    struct tm tm = {};
+
+    localtime_r(&now, &tm);
+    g_lTimeZoneOffset = tm.tm_gmtoff;
+#else
     TZSET();
+#endif
   }
+#if defined(OS_BSD)
+  tz_minutes_ = static_cast<int8_t>((abs(g_lTimeZoneOffset) % 3600) / 60);
+#else
   tz_minutes_ = TIMEZONE / -60;
+#endif
 }
 
 CXFA_TimeZoneProvider::~CXFA_TimeZoneProvider() = default;
