--- net/url_request/url_fetcher.h.orig	2021-04-14 01:08:53 UTC
+++ net/url_request/url_fetcher.h
@@ -352,8 +352,8 @@ class NET_EXPORT URLFetcher {
   // annotations on Linux & Windows.
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if (!defined(OS_WIN) &&                                       \
-     !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))) || \
+#if (!defined(OS_WIN) &&                                                          \
+     !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))) || \
     defined(OS_CHROMEOS)
   // |url| is the URL to send the request to. It must be valid.
   // |request_type| is the type of request to make.
