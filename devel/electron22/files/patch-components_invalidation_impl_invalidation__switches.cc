--- components/invalidation/impl/invalidation_switches.cc.orig	2022-11-30 08:12:58 UTC
+++ components/invalidation/impl/invalidation_switches.cc
@@ -21,7 +21,7 @@ const int kDefaultInstanceIDTokenTTLSeconds = 14 * 24 
 BASE_FEATURE(kSyncInstanceIDTokenTTL,
              "SyncInstanceIDTokenTTL",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
