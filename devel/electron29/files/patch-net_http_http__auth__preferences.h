--- net/http/http_auth_preferences.h.orig	2023-10-19 19:58:28 UTC
+++ net/http/http_auth_preferences.h
@@ -50,7 +50,7 @@ class NET_EXPORT HttpAuthPreferences {
 #if BUILDFLAG(IS_ANDROID)
   virtual std::string AuthAndroidNegotiateAccountType() const;
 #endif
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual bool AllowGssapiLibraryLoad() const;
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
   virtual bool CanUseDefaultCredentials(
@@ -86,7 +86,7 @@ class NET_EXPORT HttpAuthPreferences {
   }
 #endif  // BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void set_allow_gssapi_library_load(bool allow_gssapi_library_load) {
     allow_gssapi_library_load_ = allow_gssapi_library_load;
   }
@@ -137,7 +137,7 @@ class NET_EXPORT HttpAuthPreferences {
   std::string auth_android_negotiate_account_type_;
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool allow_gssapi_library_load_ = true;
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
