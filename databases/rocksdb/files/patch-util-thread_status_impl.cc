--- util/thread_status_impl.cc.orig	2015-05-20 01:42:17 UTC
+++ util/thread_status_impl.cc
@@ -100,7 +100,7 @@ std::map<std::string, uint64_t>
       property_map.insert(
           {"BaseInputLevel", op_properties[i] >> 32});
       property_map.insert(
-          {"OutputLevel", op_properties[i] % (1LU << 32)});
+          {"OutputLevel", op_properties[i] % ((uint64_t) 1LU << 32)});
     } else if (op_type == OP_COMPACTION &&
                i == COMPACTION_PROP_FLAGS) {
       property_map.insert(
