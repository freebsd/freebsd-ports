--- src/fileselector/fileselect.cxx.orig	2009-01-17 14:56:02.000000000 -0500
+++ src/fileselector/fileselect.cxx	2009-01-17 15:04:34.000000000 -0500
@@ -67,7 +67,7 @@
 const char* FSEL::get_file(void)
 {
 	// Calling directory() is apparently not enough on Linux
-#ifdef __linux__
+#if  defined(__linux__) || defined(__FreeBSD__)
 	const char* preset = chooser->preset_file();
 	if (preset && *preset != '/' && chooser->directory()) {
 		filename = chooser->directory();
