https://gitlab.freedesktop.org/emersion/libliftoff/-/issues/80

--- layer.c.orig	2024-05-27 22:22:40 UTC
+++ layer.c
@@ -73,7 +73,7 @@ layer_get_property(struct liftoff_layer *layer, const 
 
 	core_prop_idx = core_property_index(name);
 	if (core_prop_idx >= 0) {
-		return layer_get_core_property(layer, core_prop_idx);
+		return layer_get_core_property(layer, (enum liftoff_core_property)core_prop_idx);
 	}
 
 	for (i = 0; i < layer->props_len; i++) {
