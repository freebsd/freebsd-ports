--- chrome/browser/ui/views/profiles/profile_menu_view_base.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_view_base.cc
@@ -698,7 +698,7 @@ void ProfileMenuViewBase::SetProfileIdentityInfo(
       image_model, management_badge, this,
       ProfileMenuViewBase::kIdentityImageSize, kIdentityImageBorder);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // crbug.com/1161166: Orca does not read the accessible window title of the
   // bubble, so we duplicate it in the top-level menu item. To be revisited
   // after considering other options, including fixes on the AT side.
