--- chrome/browser/webauthn/authenticator_request_dialog_model.cc.orig	2023-10-19 19:58:08 UTC
+++ chrome/browser/webauthn/authenticator_request_dialog_model.cc
@@ -495,7 +495,11 @@ void AuthenticatorRequestDialogModel::
     // extra step. Jump to Windows instead.
     if (base::FeatureList::IsEnabled(device::kWebAuthnNewPasskeyUI) &&
         transport_availability_.has_win_native_api_authenticator &&
+#if (_LIBCPP_VERSION >= 160000)
         std::ranges::all_of(mechanisms_, [](const auto& mech) {
+#else
+        base::ranges::all_of(mechanisms_, [](const auto& mech) {
+#endif
           return absl::holds_alternative<Mechanism::WindowsAPI>(mech.type) ||
                  (absl::holds_alternative<Mechanism::Credential>(mech.type) &&
                   absl::get<Mechanism::Credential>(mech.type).value().source ==
