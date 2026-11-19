--- third_party/blink/renderer/core/page/context_menu_controller.cc.orig	2026-11-19 08:31:38 UTC
+++ third_party/blink/renderer/core/page/context_menu_controller.cc
@@ -662,7 +662,7 @@ bool ContextMenuController::ShowContextMenu(
       data.media_type = mojom::blink::ContextMenuDataMediaType::kCanvas;
       const auto* canvas = To<HTMLCanvasElement>(potential_image_node);
       data.has_image_contents = canvas->OriginClean();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // TODO(crbug.com/40902474): Support reading from the WebGPU front buffer
       // on Linux and remove the below code, which results in "Copy Image" and
       // "Save Image To" being grayed out in the context menu.
