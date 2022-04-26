--- src/cmake/pluginval.cmake.orig	2022-03-28 01:22:52 UTC
+++ src/cmake/pluginval.cmake
@@ -35,8 +35,8 @@
     add_dependencies(surge-pluginval-all ${name})
   endfunction()
 
-  create_pluginval_target(surge-xt-pluginval-vst3 surge-xt_VST3 "Surge XT.vst3")
-  create_pluginval_target(surge-fx-pluginval-vst3 surge-fx_VST3 "${SURGE_FX_PRODUCT_NAME}.vst3")
+  #create_pluginval_target(surge-xt-pluginval-vst3 surge-xt_VST3 "Surge XT.vst3")
+  #create_pluginval_target(surge-fx-pluginval-vst3 surge-fx_VST3 "${SURGE_FX_PRODUCT_NAME}.vst3")
 
   if (APPLE)
     create_pluginval_target(surge-xt-pluginval-au surge-xt_AU "Surge XT.component")
