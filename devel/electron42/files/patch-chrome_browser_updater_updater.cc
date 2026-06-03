--- chrome/browser/updater/updater.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/updater/updater.cc
@@ -53,7 +53,7 @@ std::optional<mojom::AppState> GetLastKnownUpdaterRegi
   return GetLastKnownUpdaterRegistrationStorage();
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 void CheckForUpdate(
     base::RepeatingCallback<void(const UpdateService::UpdateState&)> callback) {
   base::ThreadPool::PostTaskAndReplyWithResult(
