--- chrome/browser/ui/views/profiles/profile_menu_view_base.cc.orig	2021-04-14 01:08:41 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_view_base.cc
@@ -573,7 +573,7 @@ void ProfileMenuViewBase::SetProfileIdentityInfo(
 
   auto avatar_image_view = std::make_unique<AvatarImageView>(image_model, this);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // crbug.com/1161166: Orca does not read the accessible window title of the
   // bubble, so we duplicate it in the top-level menu item. To be revisited
   // after considering other options, including fixes on the AT side.
