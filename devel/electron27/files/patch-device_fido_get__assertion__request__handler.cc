--- device/fido/get_assertion_request_handler.cc.orig	2023-10-19 19:58:23 UTC
+++ device/fido/get_assertion_request_handler.cc
@@ -370,7 +370,11 @@ bool AllowListOnlyHybridOrInternal(const CtapGetAssert
 
 bool AllowListIncludedTransport(const CtapGetAssertionRequest& request,
                                 FidoTransportProtocol transport) {
+#if (_LIBCPP_VERSION >= 160000)
   return std::ranges::any_of(
+#else
+  return base::ranges::any_of(
+#endif
       request.allow_list,
       [transport](const PublicKeyCredentialDescriptor& cred) {
         return cred.transports.empty() ||
@@ -441,7 +445,11 @@ void GetAssertionRequestHandler::PreselectAccount(
     PublicKeyCredentialDescriptor credential) {
   DCHECK(!preselected_credential_);
   DCHECK(request_.allow_list.empty() ||
+#if (_LIBCPP_VERSION >= 160000)
          std::ranges::any_of(
+#else
+         base::ranges::any_of(
+#endif
              request_.allow_list,
              [&credential](const PublicKeyCredentialDescriptor& desc) {
                return desc.id == credential.id;
