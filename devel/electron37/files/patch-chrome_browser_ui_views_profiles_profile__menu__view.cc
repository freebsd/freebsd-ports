--- chrome/browser/ui/views/profiles/profile_menu_view.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_view.cc
@@ -92,7 +92,7 @@
 #include "ui/strings/grit/ui_strings.h"
 #include "ui/views/accessibility/view_accessibility.h"
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #endif
 
@@ -418,7 +418,7 @@ void ProfileMenuView::OnSigninButtonClicked(
   }
   GetWidget()->CloseWithReason(views::Widget::ClosedReason::kUnspecified);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/404807488): Update the button and the dialog strings.
   if (base::FeatureList::IsEnabled(switches::kEnableHistorySyncOptin)) {
     browser()->signin_view_controller()->ShowModalHistorySyncOptInDialog();
@@ -555,7 +555,7 @@ void ProfileMenuView::SetMenuTitleForAccessibility() {
     case signin_util::SignedInState::kSignedOut:
     case signin_util::SignedInState::kWebOnlySignedIn: {
       std::string profile_user_display_name, profile_user_email;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       profile_user_display_name = profile->GetPrefs()->GetString(
           enterprise_signin::prefs::kProfileUserDisplayName);
       profile_user_email = profile->GetPrefs()->GetString(
