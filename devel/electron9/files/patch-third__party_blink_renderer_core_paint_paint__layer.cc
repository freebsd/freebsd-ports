--- third_party/blink/renderer/core/paint/paint_layer.cc.orig	2020-05-26 08:03:26 UTC
+++ third_party/blink/renderer/core/paint/paint_layer.cc
@@ -107,7 +107,7 @@ namespace {
 static CompositingQueryMode g_compositing_query_mode =
     kCompositingQueriesAreOnlyAllowedInCertainDocumentLifecyclePhases;
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
 struct SameSizeAsPaintLayer : DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
