--- base/i18n/icu_util.cc.orig	2022-05-25 04:00:43 UTC
+++ base/i18n/icu_util.cc
@@ -52,7 +52,7 @@
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) ||   \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
      !BUILDFLAG(IS_CHROMECAST))
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
@@ -324,7 +324,7 @@ void InitializeIcuTimeZone() {
       FuchsiaIntlProfileWatcher::GetPrimaryTimeZoneIdForIcuInitialization();
   icu::TimeZone::adoptDefault(
       icu::TimeZone::createTimeZone(icu::UnicodeString::fromUTF8(zone_id)));
-#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     !BUILDFLAG(IS_CHROMECAST)
   // To respond to the time zone change properly, the default time zone
   // cache in ICU has to be populated on starting up.
