--- net/http/http_auth_preferences.cc.orig	2023-10-19 19:58:28 UTC
+++ net/http/http_auth_preferences.cc
@@ -39,7 +39,7 @@ std::string HttpAuthPreferences::AuthAndroidNegotiateA
 }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool HttpAuthPreferences::AllowGssapiLibraryLoad() const {
   return allow_gssapi_library_load_;
 }
