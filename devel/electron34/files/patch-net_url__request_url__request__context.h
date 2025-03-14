--- net/url_request/url_request_context.h.orig	2025-01-27 17:37:37 UTC
+++ net/url_request/url_request_context.h
@@ -92,7 +92,7 @@ class NET_EXPORT URLRequestContext final {
 // TODO(crbug.com/40118868): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   // This function should not be used in Chromium, please use the version with
   // NetworkTrafficAnnotationTag in the future.
   //
