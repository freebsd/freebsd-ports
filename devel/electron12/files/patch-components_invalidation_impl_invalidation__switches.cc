--- components/invalidation/impl/invalidation_switches.cc.orig	2021-04-14 01:08:45 UTC
+++ components/invalidation/impl/invalidation_switches.cc
@@ -28,7 +28,7 @@ const base::Feature kFCMInvalidationsForSyncDontCheckV
 
 const base::Feature kSyncInstanceIDTokenTTL {
   "SyncInstanceIDTokenTTL",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_IOS)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
