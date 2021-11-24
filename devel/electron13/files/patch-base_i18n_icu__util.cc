--- base/i18n/icu_util.cc.orig	2021-07-15 19:13:29 UTC
+++ base/i18n/icu_util.cc
@@ -49,7 +49,7 @@
 #include "third_party/icu/source/common/unicode/unistr.h"
 #endif
 
-#if defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
+#if defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !BUILDFLAG(IS_CHROMECAST))
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 #endif
@@ -343,7 +343,7 @@ void InitializeIcuTimeZone() {
       FuchsiaIntlProfileWatcher::GetPrimaryTimeZoneIdForIcuInitialization();
   icu::TimeZone::adoptDefault(
       icu::TimeZone::createTimeZone(icu::UnicodeString::fromUTF8(zone_id)));
-#elif (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !BUILDFLAG(IS_CHROMECAST)
+#elif (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMECAST)
   // To respond to the time zone change properly, the default time zone
   // cache in ICU has to be populated on starting up.
   // See TimeZoneMonitorLinux::NotifyClientsFromImpl().
