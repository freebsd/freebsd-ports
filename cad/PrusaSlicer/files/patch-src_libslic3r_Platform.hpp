--- src/libslic3r/Platform.hpp.orig	2021-04-20 12:26:01 UTC
+++ src/libslic3r/Platform.hpp
@@ -28,6 +28,7 @@ enum class PlatformFlavor
 	WSL2,
 	// For Platform::BSDUnix
 	OpenBSD,
+	FreeBSD,
 };
 
 // To be called on program start-up.
