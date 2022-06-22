--- chrome/browser/ui/views/tabs/tab.cc.orig	2022-05-19 05:17:39 UTC
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -580,7 +580,7 @@ void Tab::MaybeUpdateHoverStatus(const ui::MouseEvent&
   if (mouse_hovered_ || !GetWidget()->IsMouseEventsEnabled())
     return;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug.com/978134): Once Linux/CrOS widget transparency is solved,
