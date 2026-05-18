--- components/feature_engagement/public/event_constants.cc.orig	2025-01-27 17:37:37 UTC
+++ components/feature_engagement/public/event_constants.cc
@@ -11,7 +11,7 @@ namespace events {
 namespace events {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kNewTabOpened[] = "new_tab_opened";
 const char kSixthTabOpened[] = "sixth_tab_opened";
 const char kReadingListItemAdded[] = "reading_list_item_added";
