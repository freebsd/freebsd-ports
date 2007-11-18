--- guiExtended/progress.h.orig	2007-11-12 17:24:08.000000000 +0100
+++ guiExtended/progress.h	2007-11-12 17:24:34.000000000 +0100
@@ -43,7 +43,7 @@
 	/** if width of the resource is greater then its height then makes
 		a horizontal, else makes a vertical progress bar
 	*/
-	KrProgress::KrProgress (int width,
+	KrProgress (int width,
 							int height,
 							KrRGBA FillColor,
 							KrRGBA ChangeColor,
@@ -53,7 +53,7 @@
 	/** if width of the resource is greater then its height then makes
 		a horizontal, else makes a vertical progress bar
 	*/
-	KrProgress::KrProgress (int width,
+	KrProgress (int width,
 							int height,
 							const KrScheme& scheme);
 
