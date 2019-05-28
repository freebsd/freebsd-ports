--- chrome/browser/ui/views/tabs/new_tab_button.cc.orig	2019-03-15 06:37:07 UTC
+++ chrome/browser/ui/views/tabs/new_tab_button.cc
@@ -94,7 +94,7 @@ NewTabButton::NewTabButton(TabStrip* tab_strip, views:
       tab_strip_(tab_strip),
       is_incognito_(tab_strip->IsIncognito()) {
   set_animate_on_state_change(true);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   set_triggerable_event_flags(triggerable_event_flags() |
                               ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
