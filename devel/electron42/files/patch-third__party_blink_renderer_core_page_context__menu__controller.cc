--- third_party/blink/renderer/core/page/context_menu_controller.cc.orig	2026-04-28 21:06:17 UTC
+++ third_party/blink/renderer/core/page/context_menu_controller.cc
@@ -661,7 +661,7 @@ bool ContextMenuController::ShowContextMenu(
     if (potential_image_node != nullptr &&
         IsA<HTMLCanvasElement>(potential_image_node)) {
       data.media_type = mojom::blink::ContextMenuDataMediaType::kCanvas;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/40902474): Support reading from the WebGPU front buffer
       // on Linux and remove the below code, which results in "Copy Image" and
       // "Save Image To" being grayed out in the context menu.
