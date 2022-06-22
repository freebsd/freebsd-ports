--- net/url_request/url_request_context.h.orig	2022-05-19 05:17:45 UTC
+++ net/url_request/url_request_context.h
@@ -83,7 +83,7 @@ class NET_EXPORT URLRequestContext {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   // This function should not be used in Chromium, please use the version with
   // NetworkTrafficAnnotationTag in the future.
   //
