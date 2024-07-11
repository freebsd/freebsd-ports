--- components/cookie_config/cookie_store_util.cc.orig	2024-02-21 00:20:40 UTC
+++ components/cookie_config/cookie_store_util.cc
@@ -12,7 +12,7 @@ namespace cookie_config {
 namespace cookie_config {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
