--- chrome/browser/signin/chrome_signin_client.cc.orig	2026-10-19 21:50:55 UTC
+++ chrome/browser/signin/chrome_signin_client.cc
@@ -167,7 +167,7 @@ std::string HatsSurveyTriggerForAccessPoint(
 std::string HatsSurveyTriggerForAccessPoint(
     signin_metrics::AccessPoint access_point) {
   switch (access_point) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case signin_metrics::AccessPoint::kAddressBubble:
       return kHatsSurveyTriggerIdentityAddressBubbleSignin;
     case signin_metrics::AccessPoint::kAvatarBubbleSignIn:
