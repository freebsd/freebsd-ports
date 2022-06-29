--- chrome/browser/policy/browser_signin_policy_handler.cc.orig	2022-05-25 04:00:48 UTC
+++ chrome/browser/policy/browser_signin_policy_handler.cc
@@ -44,7 +44,7 @@ void BrowserSigninPolicyHandler::ApplyPolicySettings(c
       policies.GetValue(policy_name(), base::Value::Type::INTEGER);
   switch (static_cast<BrowserSigninMode>(value->GetInt())) {
     case BrowserSigninMode::kForced:
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
       prefs->SetValue(prefs::kForceBrowserSignin, base::Value(true));
 #endif
       [[fallthrough]];
