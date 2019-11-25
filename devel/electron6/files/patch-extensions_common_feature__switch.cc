--- extensions/common/feature_switch.cc.orig	2019-09-10 11:14:04 UTC
+++ extensions/common/feature_switch.cc
@@ -44,11 +44,7 @@ class CommonSwitches {
                          FeatureSwitch::DEFAULT_ENABLED),
         load_media_router_component_extension(
             kLoadMediaRouterComponentExtensionFlag,
-#if defined(GOOGLE_CHROME_BUILD)
             FeatureSwitch::DEFAULT_ENABLED)
-#else
-            FeatureSwitch::DEFAULT_DISABLED)
-#endif  // defined(GOOGLE_CHROME_BUILD)
   {
   }
 
