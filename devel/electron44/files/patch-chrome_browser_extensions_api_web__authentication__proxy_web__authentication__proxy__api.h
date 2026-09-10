--- chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_api.h.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_api.h
@@ -15,7 +15,7 @@
 #include "extensions/browser/extension_function_histogram_value.h"
 
 // This API is limited to Win/Mac/Linux.
-static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 namespace extensions {
 
