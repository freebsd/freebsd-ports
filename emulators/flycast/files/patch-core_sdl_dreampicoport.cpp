--- core/sdl/dreampicoport.cpp.orig	2026-01-12 19:16:59 UTC
+++ core/sdl/dreampicoport.cpp
@@ -120,7 +120,7 @@ class DreamPicoPortSerialHandler (public)
 		std::this_thread::sleep_for(std::chrono::milliseconds(500));
 
 		serial_handler = asio::serial_port(io_context);
-		io_context.reset();
+		io_context.restart();
 
 		std::string serial_device = "";
 
