--- chrome/browser/ui/tabs/tab_features.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/ui/tabs/tab_features.cc
@@ -99,7 +99,7 @@
 #include "components/multistep_filter/core/features.h"
 #include "components/skills/features.h"
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/contextual_tasks/contextual_tasks_tab_visit_tracker.h"
 #include "chrome/browser/record_replay/chrome_record_replay_client.h"
 #include "chrome/browser/ui/views/location_bar/record_replay_page_action_controller.h"
@@ -484,7 +484,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
   task_manager::WebContentsTags::CreateForTabContents(tab.GetContents());
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   inactive_window_mouse_event_controller_ =
       std::make_unique<InactiveWindowMouseEventController>();
 
@@ -552,7 +552,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
         std::make_unique<back_to_opener::BackToOpenerController>(tab);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(enterprise_reporting::kSaasUsageReporting)) {
     saas_usage_navigation_observer_ =
         std::make_unique<enterprise_reporting::SaasUsageNavigationObserver>(
@@ -561,7 +561,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(multistep_filter::kMultistepFilter)) {
     filter_ui_controller_ =
         GetUserDataFactory()
