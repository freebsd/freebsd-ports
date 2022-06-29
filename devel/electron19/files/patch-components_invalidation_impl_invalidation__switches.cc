--- components/invalidation/impl/invalidation_switches.cc.orig	2022-05-19 03:45:24 UTC
+++ components/invalidation/impl/invalidation_switches.cc
@@ -21,7 +21,7 @@ const int kDefaultInstanceIDTokenTTLSeconds = 14 * 24 
 const base::Feature kSyncInstanceIDTokenTTL {
   "SyncInstanceIDTokenTTL",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
