--- components/password_manager/core/browser/password_form_filling.cc.orig	2025-06-30 07:04:30 UTC
+++ components/password_manager/core/browser/password_form_filling.cc
@@ -165,7 +165,7 @@ LikelyFormFilling SendFillInformationToRenderer(
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (!should_show_popup_without_passwords) {
       client->MaybeShowSavePasswordPrimingPromo(observed_form.url);
     }
