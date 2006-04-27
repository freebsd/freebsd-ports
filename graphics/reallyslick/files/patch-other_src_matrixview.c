--- other_src/matrixview.c.orig	Sun Feb 26 08:55:26 2006
+++ other_src/matrixview.c	Fri Apr 28 09:33:18 2006
@@ -94,13 +94,15 @@
 
 // Directory scanning + image loading code in a separate function callable either from loadNextImage or another thread if pthreads is available.
 void loadNextImageFromDisk() {
-	MagickWand *magick_wand = NewMagickWand();
+	MagickWand *magick_wand;
 	ExceptionInfo exception;
 	int dirLoop = 0;
+	int imageLoaded = 0;
+
+	magick_wand = NewMagickWand();
 
 	GetExceptionInfo (&exception);
 
-	int imageLoaded = 0;
 	do {
 		struct dirent *file;
 
