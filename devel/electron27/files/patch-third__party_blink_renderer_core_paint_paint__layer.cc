--- third_party/blink/renderer/core/paint/paint_layer.cc.orig	2023-10-19 19:58:32 UTC
+++ third_party/blink/renderer/core/paint/paint_layer.cc
@@ -118,7 +118,7 @@ namespace blink {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 struct SameSizeAsPaintLayer : GarbageCollected<PaintLayer>, DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
