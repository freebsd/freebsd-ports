--- content/browser/webid/idp_network_request_manager.cc.orig	2023-10-19 19:58:22 UTC
+++ content/browser/webid/idp_network_request_manager.cc
@@ -604,7 +604,11 @@ void OnTokenRequestParsed(
     if (response_error) {
       int error_code = response_error->FindInt(kErrorCodeKey).value_or(0);
       GURL error_url = ExtractUrl(*response_error, kErrorUrlKey);
+#if defined(__clang__) && (__clang_major__ >= 16)
       token_result.error = TokenError(error_code, error_url);
+#else
+      token_result.error = TokenError(TokenError{error_code, error_url});
+#endif
     }
   }
 
