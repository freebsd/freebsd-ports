--- components/cookie_config/cookie_store_util.cc.orig	2022-05-19 03:45:23 UTC
+++ components/cookie_config/cookie_store_util.cc
@@ -12,7 +12,7 @@
 namespace cookie_config {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
