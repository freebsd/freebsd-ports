--- main.cpp.orig	2011-05-19 03:38:25 UTC
+++ main.cpp
@@ -115,6 +115,10 @@ int main(int argc, char *argv[])
 
     else if (next_option == -1)
     {
+	// Strip file://, added by some file browsers
+	if ( memcmp(argv[1], "file://", 7) == 0 )
+	    memmove(argv[1], argv[1]+7, strlen(argv[1]) - 6);
+	puts(argv[1]);
         MainWindow imageViewer;
         if (QApplication::arguments().size() > 1)
             imageViewer.openImageFromCommandLine(QApplication::arguments());
