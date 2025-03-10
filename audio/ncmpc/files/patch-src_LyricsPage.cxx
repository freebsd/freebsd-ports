--- src/LyricsPage.cxx.orig	2024-09-14 23:59:12 UTC
+++ src/LyricsPage.cxx
@@ -28,7 +28,7 @@ using std::string_view_literals::operator""sv;
 
 using std::string_view_literals::operator""sv;
 
-#ifdef __APPLE__
+#ifdef __FreeBSD__
 extern char **environ;
 #endif
 
