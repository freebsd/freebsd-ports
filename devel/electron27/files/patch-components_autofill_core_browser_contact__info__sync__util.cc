--- components/autofill/core/browser/contact_info_sync_util.cc.orig	2023-10-19 19:58:16 UTC
+++ components/autofill/core/browser/contact_info_sync_util.cc
@@ -174,9 +174,15 @@ class ContactInfoProfileSetter {
     CHECK(observations.empty());
     for (const sync_pb::ContactInfoSpecifics::Observation& proto_observation :
          proto_observations) {
+#if defined(__clang__) && (__clang_major__ >= 15)
       observations.emplace_back(proto_observation.type(),
                                 ProfileTokenQuality::FormSignatureHash(
                                     proto_observation.form_hash()));
+#else
+      observations.emplace_back() = { static_cast<unsigned char>(proto_observation.type()),
+                                ProfileTokenQuality::FormSignatureHash(
+                                    proto_observation.form_hash()) };
+#endif
     }
   }
 
