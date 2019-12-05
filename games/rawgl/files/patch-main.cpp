--- main.cpp.orig	2018-03-21 01:29:10 UTC
+++ main.cpp
@@ -83,7 +83,7 @@ static const int DEFAULT_WINDOW_H = 400;
 int main(int argc, char *argv[]) {
 	char *dataPath = 0;
 	int part = 16001;
-	Language lang = LANG_FR;
+	Language lang = LANG_US;
 	int graphicsType = GRAPHICS_GL;
 	DisplayMode dm;
 	dm.mode   = DisplayMode::WINDOWED;
