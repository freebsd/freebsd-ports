--- ./src/HelpBrowser/LuminancePaths.cpp.orig
+++ ./src/HelpBrowser/LuminancePaths.cpp
@@ -35,8 +35,6 @@ QString LuminancePaths::HelpDir()
   hf = LocalizedDirPath(QApplication::applicationDirPath() + dirsep + "../Resources/help/en" + dirsep);
 #elif _WIN32
   hf = LocalizedDirPath(QApplication::applicationDirPath() + dirsep + "help" + dirsep);
-#elif __FreeBSD__
-  hf = LocalizedDirPath("/usr/local/share/doc/luminance-hdr/");
 #else
   //	hf = LocalizedDirPath( PREFIX + dirsep + "share" + dirsep + "fontmatrix" + dirsep + "help" + dirsep );
   //hf = LocalizedDirPath("usr" + dirsep + "share" + dirsep + "luminance-hdr" + dirsep + "help" + dirsep);
