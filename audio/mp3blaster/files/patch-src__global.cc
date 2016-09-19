--- src/global.cc.orig	2016-09-12 14:29:38.335706000 -0400
+++ src/global.cc	2016-09-12 14:26:46.344490000 -0400
@@ -371,7 +371,7 @@
 is_sid(const char *filename)
 {
 #ifdef HAVE_SIDPLAYER
-	char *ext = strrchr(filename, '.');
+	const char *ext = strrchr(filename, '.');
 	if (ext) {
 		if (!strcasecmp(ext, ".psid")) return 1;
 		if (!strcasecmp(ext, ".sid")) return 1;
