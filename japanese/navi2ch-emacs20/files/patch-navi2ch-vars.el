--- navi2ch-vars.el.orig	Fri Jul 26 22:55:11 2002
+++ navi2ch-vars.el	Mon Jul 29 12:35:07 2002
@@ -832,7 +832,7 @@
 (defcustom navi2ch-icon-directory
   (cond ((fboundp 'locate-data-directory)
 	 (locate-data-directory "navi2ch"))
-	((let ((icons (expand-file-name "navi2ch/icons/"
+	((let ((icons (expand-file-name "navi2ch/"
 					data-directory)))
 	   (if (file-directory-p icons)
 	       icons)))
