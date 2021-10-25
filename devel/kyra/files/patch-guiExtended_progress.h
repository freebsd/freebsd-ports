--- guiExtended/progress.h.orig	2004-11-21 19:28:32 UTC
+++ guiExtended/progress.h
@@ -43,7 +43,7 @@ class KrProgress : public KrWidget (public)
 	/** if width of the resource is greater then its height then makes
 		a horizontal, else makes a vertical progress bar
 	*/
-	KrProgress::KrProgress (int width,
+	KrProgress (int width,
 							int height,
 							KrRGBA FillColor,
 							KrRGBA ChangeColor,
@@ -53,7 +53,7 @@ class KrProgress : public KrWidget (public)
 	/** if width of the resource is greater then its height then makes
 		a horizontal, else makes a vertical progress bar
 	*/
-	KrProgress::KrProgress (int width,
+	KrProgress (int width,
 							int height,
 							const KrScheme& scheme);
 
