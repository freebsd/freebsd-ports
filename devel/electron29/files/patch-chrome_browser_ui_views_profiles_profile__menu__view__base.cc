--- chrome/browser/ui/views/profiles/profile_menu_view_base.cc.orig	2024-02-21 00:20:37 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_view_base.cc
@@ -672,7 +672,7 @@ void ProfileMenuViewBase::SetProfileIdentityInfo(
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // crbug.com/1161166: Orca does not read the accessible window title of the
   // bubble, so we duplicate it in the top-level menu item. To be revisited
   // after considering other options, including fixes on the AT side.
