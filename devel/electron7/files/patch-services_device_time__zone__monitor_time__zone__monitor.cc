--- services/device/time_zone_monitor/time_zone_monitor.cc.orig	2019-12-12 12:39:56 UTC
+++ services/device/time_zone_monitor/time_zone_monitor.cc
@@ -29,7 +29,7 @@ void TimeZoneMonitor::Bind(device::mojom::TimeZoneMoni
 
 void TimeZoneMonitor::NotifyClients() {
   DCHECK(thread_checker_.CalledOnValidThread());
-#if defined(OS_CHROMEOS) || (defined(OS_LINUX) && defined(IS_CHROMECAST))
+#if defined(OS_CHROMEOS) || ((defined(OS_BSD) || defined(OS_LINUX)) && defined(IS_CHROMECAST))
   // On CrOS (and Chromecast), ICU's default tz is already set to a new zone. No
   // need to redetect it with detectHostTimeZone().
   std::unique_ptr<icu::TimeZone> new_zone(icu::TimeZone::createDefault());
@@ -41,7 +41,7 @@ void TimeZoneMonitor::NotifyClients() {
 #else
   std::unique_ptr<icu::TimeZone> new_zone(icu::TimeZone::detectHostTimeZone());
 #endif
-#if defined(OS_LINUX) && !defined(IS_CHROMECAST)
+#if (defined(OS_LINUX) && !defined(IS_CHROMECAST)) || defined(OS_BSD)
   // We get here multiple times on Linux per a single tz change, but
   // want to update the ICU default zone and notify renderer only once.
   std::unique_ptr<icu::TimeZone> current_zone(icu::TimeZone::createDefault());
