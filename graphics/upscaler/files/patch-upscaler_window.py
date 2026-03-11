Avoid spurious error "Algorithm failed" as poll() returns None when
the subprocess hasn't finished yet.

Revert: https://gitlab.gnome.org/World/Upscaler/-/commit/3c88bab3

--- upscaler/window.py.orig	2025-12-15 16:42:07 UTC
+++ upscaler/window.py
@@ -410,7 +410,7 @@ class Window(Adw.ApplicationWindow):
         async def run() -> None:
             def start_process(running_row: QueueRow) -> None:
                 running_row.command = (
-                    "upscayl-bin",
+                    "realesrgan-ncnn-vulkan",
                     "-i",
                     str(running_row.media_file.get_preferred_input_path()),
                     "-o",
@@ -445,7 +445,7 @@ class Window(Adw.ApplicationWindow):
                             bad = bad or re.match(warn, line) is not None
 
                 # Process algorithm output
-                result = running_row.process.poll()
+                result = running_row.process.wait(1)
                 if running_row.canceled:
                     logger.info("Manually canceled upscaling by the user")
 
