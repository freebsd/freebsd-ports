--- src/slic3r/GUI/RemovableDriveManager.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/RemovableDriveManager.cpp
@@ -744,7 +744,7 @@ namespace search_for_drives_internal 
 		//confirms if the file is removable drive and adds it to vector
 
 		if (
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 			// Chromium mounts removable drives in a way that produces the same device ID.
 			platform_flavor() == PlatformFlavor::LinuxOnChromium ||
 #endif
