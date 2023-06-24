--- src/mongo/s/write_ops/write_op.h.orig	2023-06-15 22:07:57 UTC
+++ src/mongo/s/write_ops/write_op.h
@@ -38,7 +38,7 @@ struct TargetedWrite;
 namespace mongo {
 
 struct TargetedWrite;
-struct ChildWriteOp;
+class WriteOp;
 
 enum WriteOpState {
     // Item is ready to be targeted
@@ -63,6 +63,31 @@ enum WriteOpState {
 };
 
 /**
+ * State of a write in-progress (to a single shard) which is one part of a larger write
+ * operation.
+ *
+ * As above, the write op may finish in either a successful (_Completed) or unsuccessful
+ * (_Error) state.
+ */
+struct ChildWriteOp {
+    ChildWriteOp(WriteOp* const parent) : parentOp(parent) {}
+
+    const WriteOp* const parentOp;
+
+    WriteOpState state{WriteOpState_Ready};
+
+    // non-zero when state == _Pending
+    // Not owned here but tracked for reporting
+    TargetedWrite* pendingWrite{nullptr};
+
+    // filled when state > _Pending
+    std::unique_ptr<ShardEndpoint> endpoint;
+
+    // filled when state == _Error or (optionally) when state == _Cancelled
+    boost::optional<write_ops::WriteError> error;
+};
+
+/**
  * State of a single write item in-progress from a client request.
  *
  * The lifecyle of a write op:
@@ -182,30 +207,6 @@ class WriteOp { (private)
 
     // stores the shards where this write operation succeeded
     absl::flat_hash_set<ShardId> _successfulShardSet;
-};
-/**
- * State of a write in-progress (to a single shard) which is one part of a larger write
- * operation.
- *
- * As above, the write op may finish in either a successful (_Completed) or unsuccessful
- * (_Error) state.
- */
-struct ChildWriteOp {
-    ChildWriteOp(WriteOp* const parent) : parentOp(parent) {}
-
-    const WriteOp* const parentOp;
-
-    WriteOpState state{WriteOpState_Ready};
-
-    // non-zero when state == _Pending
-    // Not owned here but tracked for reporting
-    TargetedWrite* pendingWrite{nullptr};
-
-    // filled when state > _Pending
-    std::unique_ptr<ShardEndpoint> endpoint;
-
-    // filled when state == _Error or (optionally) when state == _Cancelled
-    boost::optional<write_ops::WriteError> error;
 };
 
 // First value is write item index in the batch, second value is child write op index
