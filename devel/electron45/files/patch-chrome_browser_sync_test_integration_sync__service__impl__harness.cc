--- chrome/browser/sync/test/integration/sync_service_impl_harness.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/sync/test/integration/sync_service_impl_harness.cc
@@ -489,7 +489,7 @@ bool SyncServiceImplHarness::EnableHistorySyncNoWaitFo
   // Tabs and history are bundled together in the same toggle.
   service()->GetUserSettings()->SetSelectedType(
       syncer::UserSelectableType::kTabs, true);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop platforms, kSavedTabGroups are not merged to kTabs yet, but
   // they're enabled together.
   service()->GetUserSettings()->SetSelectedType(
