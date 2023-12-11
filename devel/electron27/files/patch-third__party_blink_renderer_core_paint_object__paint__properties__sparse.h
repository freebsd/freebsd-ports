--- third_party/blink/renderer/core/paint/object_paint_properties_sparse.h.orig	2023-10-19 19:58:32 UTC
+++ third_party/blink/renderer/core/paint/object_paint_properties_sparse.h
@@ -272,8 +272,8 @@ class CORE_EXPORT ObjectPaintPropertiesSparse : public
       NodeList& nodes,
       NodeId node_id,
       const ParentType& parent,
-      NodeType::State&& state,
-      const NodeType::AnimationState& animation_state =
+      typename NodeType::State&& state,
+      const typename NodeType::AnimationState& animation_state =
           NodeType::AnimationState()) {
     // First, check if we need to add a new node.
     if (!nodes.HasField(node_id)) {
