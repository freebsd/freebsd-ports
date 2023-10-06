--- components/webauthn/core/browser/passkey_sync_bridge.cc.orig	2023-09-05 21:57:58 UTC
+++ components/webauthn/core/browser/passkey_sync_bridge.cc
@@ -268,7 +268,11 @@ PasskeySyncBridge::GetAllPasskeys() const {
 bool PasskeySyncBridge::DeletePasskey(const std::string& credential_id) {
   // Find the credential with the given |credential_id|.
   const auto passkey_it =
+#if (_LIBCPP_VERSION >= 160000)
       std::ranges::find_if(data_, [&credential_id](const auto& passkey) {
+#else
+      base::ranges::find_if(data_, [&credential_id](const auto& passkey) {
+#endif
         return passkey.second.credential_id() == credential_id;
       });
   if (passkey_it == data_.end()) {
@@ -319,7 +323,11 @@ bool PasskeySyncBridge::UpdatePasskey(const std::strin
                                       PasskeyChange change) {
   // Find the credential with the given |credential_id|.
   const auto passkey_it =
+#if (_LIBCPP_VERSION >= 160000)
       std::ranges::find_if(data_, [&credential_id](const auto& passkey) {
+#else
+      base::ranges::find_if(data_, [&credential_id](const auto& passkey) {
+#endif
         return passkey.second.credential_id() == credential_id;
       });
   if (passkey_it == data_.end()) {
