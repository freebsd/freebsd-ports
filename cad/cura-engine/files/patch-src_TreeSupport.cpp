--- src/TreeSupport.cpp.orig	2024-04-02 12:26:14 UTC
+++ src/TreeSupport.cpp
@@ -2232,7 +2232,7 @@ void TreeSupport::finalizeInterfaceAndSupportAreas(
                     floor_layer.add(layer_outset.intersection(storage.getLayerOutlines(sample_layer, no_support, no_prime_tower)));
                     if (layers_below < config.support_bottom_layers)
                     {
-                        layers_below = std::min(layers_below + 1UL, config.support_bottom_layers);
+                        layers_below = std::min(layers_below + (size_t)1, config.support_bottom_layers);
                     }
                     else
                     {
