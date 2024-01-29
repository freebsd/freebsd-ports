--- content/public/browser/web_ui_browser_interface_broker_registry.h.orig	2023-08-10 01:48:43 UTC
+++ content/public/browser/web_ui_browser_interface_broker_registry.h
@@ -127,10 +127,10 @@ class CONTENT_EXPORT WebUIBrowserInterfaceBrokerRegist
   //
   // TODO(crbug.com/1407936): Point to WebUIJsBridge documentation.
   template <typename ControllerType>
-  JsBridgeTraits<ControllerType>::BinderInitializer& ForWebUIWithJsBridge() {
+  typename JsBridgeTraits<ControllerType>::BinderInitializer& ForWebUIWithJsBridge() {
     using Traits = JsBridgeTraits<ControllerType>;
-    using Interface = Traits::Interface;
-    using JsBridgeBinderInitializer = Traits::BinderInitializer;
+    using Interface = typename Traits::Interface;
+    using JsBridgeBinderInitializer = typename Traits::BinderInitializer;
 
     // WebUIController::GetType() requires an instantiated WebUIController
     // (because it's a virtual method and can't be static). Here we only have
