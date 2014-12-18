--- src/testshade/testshade.cpp.orig	2014-09-23 05:01:22 UTC
+++ src/testshade/testshade.cpp
@@ -733,7 +733,7 @@ test_shade (int argc, const char *argv[]
         int num_layers = 0;
         shadingsys->getattribute (shadergroup.get(), "num_layers", num_layers);
         if (num_layers > 0) {
-            std::vector<const char *> layers (num_layers, NULL);
+            std::vector<const char *> layers (size_t(num_layers), NULL);
             shadingsys->getattribute (shadergroup.get(), "layer_names",
                                       TypeDesc(TypeDesc::STRING, num_layers),
                                       &layers[0]);
