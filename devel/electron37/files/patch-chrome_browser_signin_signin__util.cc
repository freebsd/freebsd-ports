--- chrome/browser/signin/signin_util.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -80,7 +80,7 @@ void CookiesMover::StartMovingCookies() {
 CookiesMover::~CookiesMover() = default;
 
 void CookiesMover::StartMovingCookies() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool allow_cookies_to_be_moved = base::FeatureList::IsEnabled(
       profile_management::features::kThirdPartyProfileManagement);
 #else
