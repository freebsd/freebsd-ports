--- chrome/browser/policy/browser_signin_policy_handler.cc.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/policy/browser_signin_policy_handler.cc
@@ -45,7 +45,7 @@ void BrowserSigninPolicyHandler::ApplyPolicySettings(c
       policies.GetValue(policy_name(), base::Value::Type::INTEGER);
   switch (static_cast<BrowserSigninMode>(value->GetInt())) {
     case BrowserSigninMode::kForced:
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
       prefs->SetValue(prefs::kForceBrowserSignin, base::Value(true));
 #endif
       [[fallthrough]];
