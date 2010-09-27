
$FreeBSD$

--- lib/public_key/src/pubkey_cert.erl.orig
+++ lib/public_key/src/pubkey_cert.erl
@@ -223,10 +223,15 @@
 %%--------------------------------------------------------------------	
 validate_extensions(OtpCert, ValidationState, UserState, VerifyFun) ->
     TBSCert = OtpCert#'OTPCertificate'.tbsCertificate,
-    Extensions = TBSCert#'OTPTBSCertificate'.extensions,
-    validate_extensions(OtpCert, Extensions, ValidationState, no_basic_constraint,
-			is_self_signed(OtpCert), UserState, VerifyFun).
-
+    case TBSCert#'OTPTBSCertificate'.version of
+       N when N >= 3 ->
+           Extensions = TBSCert#'OTPTBSCertificate'.extensions,
+           validate_extensions(OtpCert, Extensions,
+                               ValidationState, no_basic_constraint,
+                               is_self_signed(OtpCert), UserState, VerifyFun);
+       _ -> %% Extensions not present in versions 1 & 2
+           {ValidationState, UserState}
+    end.
 %%--------------------------------------------------------------------
 -spec normalize_general_name({rdnSequence, term()}) -> {rdnSequence, term()}. 
 %%
