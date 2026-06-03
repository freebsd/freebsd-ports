--- chrome/browser/privacy_sandbox/incognito/privacy_sandbox_incognito_tab_observer.h.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/privacy_sandbox/incognito/privacy_sandbox_incognito_tab_observer.h
@@ -23,7 +23,7 @@ class PrivacySandboxIncognitoTabObserver : public cont
 
  private:
   bool IsNewTabPage(const GURL& url);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsWhatsNewPage(const GURL& url);
 #endif
 };
