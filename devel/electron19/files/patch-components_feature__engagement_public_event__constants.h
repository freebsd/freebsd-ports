--- components/feature_engagement/public/event_constants.h.orig	2022-05-19 05:17:40 UTC
+++ components/feature_engagement/public/event_constants.h
@@ -13,7 +13,7 @@ namespace events {
 
 // Desktop
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
