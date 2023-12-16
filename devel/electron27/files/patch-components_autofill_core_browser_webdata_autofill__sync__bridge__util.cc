--- components/autofill/core/browser/webdata/autofill_sync_bridge_util.cc.orig	2023-10-19 19:58:17 UTC
+++ components/autofill/core/browser/webdata/autofill_sync_bridge_util.cc
@@ -553,11 +553,19 @@ ServerCvc AutofillWalletCvcStructDataFromWalletCredent
   base::StringToInt64(wallet_credential_specifics.instrument_id(),
                       &instrument_id);
 
+#if defined(__clang__) && (__clang_major__ >= 15)
   return ServerCvc(
       instrument_id, base::UTF8ToUTF16(wallet_credential_specifics.cvc()),
       base::Time::UnixEpoch() +
           base::Milliseconds(wallet_credential_specifics
                                  .last_updated_time_unix_epoch_millis()));
+#else
+  return ServerCvc( {
+      instrument_id, base::UTF8ToUTF16(wallet_credential_specifics.cvc()),
+      base::Time::UnixEpoch() +
+          base::Milliseconds(wallet_credential_specifics
+                                 .last_updated_time_unix_epoch_millis()) });
+#endif
 }
 
 VirtualCardUsageData VirtualCardUsageDataFromUsageSpecifics(
