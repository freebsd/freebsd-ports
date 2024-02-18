--- cc/layers/mirror_layer_impl.h.orig	2023-08-12 07:07:10 UTC
+++ cc/layers/mirror_layer_impl.h
@@ -5,6 +5,7 @@
 #ifndef CC_LAYERS_MIRROR_LAYER_IMPL_H_
 #define CC_LAYERS_MIRROR_LAYER_IMPL_H_
 
+#include <cstdint>
 #include <memory>
 
 #include "base/memory/ptr_util.h"
@@ -56,7 +57,8 @@ class CC_EXPORT MirrorLayerImpl : public LayerImpl {
  private:
   const char* LayerTypeAsString() const override;
   viz::CompositorRenderPassId mirrored_layer_render_pass_id() const {
-    return viz::CompositorRenderPassId{mirrored_layer_id()};
+    return viz::CompositorRenderPassId{
+        static_cast<uint64_t>(mirrored_layer_id())};
   }
 
   int mirrored_layer_id_ = 0;
