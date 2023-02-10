--- third_party/blink/renderer/core/paint/paint_layer.cc.orig	2022-11-30 08:12:58 UTC
+++ third_party/blink/renderer/core/paint/paint_layer.cc
@@ -112,7 +112,7 @@ namespace blink {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 struct SameSizeAsPaintLayer : GarbageCollected<PaintLayer>, DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
