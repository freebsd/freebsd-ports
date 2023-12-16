--- chrome/browser/ui/views/tabs/tab_hover_card_bubble_view.cc.orig	2023-10-19 19:58:07 UTC
+++ chrome/browser/ui/views/tabs/tab_hover_card_bubble_view.cc
@@ -372,7 +372,7 @@ TabHoverCardBubbleView::TabHoverCardBubbleView(Tab* ta
   // not become active. Setting this to false creates the need to explicitly
   // hide the hovercard on press, touch, and keyboard events.
   SetCanActivate(false);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   set_accept_events(false);
 #endif
 
