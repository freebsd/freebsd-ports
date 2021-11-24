--- chrome/browser/enterprise/connectors/device_trust/device_trust_service.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service.cc
@@ -21,9 +21,9 @@ DeviceTrustService::DeviceTrustService(Profile* profil
       signal_report_callback_(
           base::BindOnce(&DeviceTrustService::OnSignalReported,
                          base::Unretained(this))) {
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   key_pair_ = std::make_unique<DeviceTrustKeyPair>();
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
   pref_observer_.Init(prefs_);
   pref_observer_.Add(kContextAwareAccessSignalsAllowlistPref,
@@ -53,9 +53,9 @@ void DeviceTrustService::OnPolicyUpdated() {
 
   if (!first_report_sent_ &&
       IsEnabled()) {  // Policy enabled for the first time.
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
     key_pair_->Init();
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
     reporter_->Init(
         base::BindRepeating(
             [](DeviceTrustService* self) { return self->IsEnabled(); },
@@ -76,9 +76,9 @@ void DeviceTrustService::OnReporterInitialized(bool su
 
   base::Value val(base::Value::Type::DICTIONARY);
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   val.SetStringKey("machine_attestion_key", key_pair_->ExportPEMPublicKey());
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
   reporter_->SendReport(std::move(val), std::move(signal_report_callback_));
 }
