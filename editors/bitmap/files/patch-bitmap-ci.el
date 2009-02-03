--- bitmap-ci.el.orig	2009-02-03 11:09:09.000000000 +0900
+++ bitmap-ci.el	2009-02-03 11:09:36.000000000 +0900
@@ -50,7 +50,8 @@
 	     "BITMAP" "BITMAP.8x16" "8x16 bitmap elements"])
 	;; `define-charset' won't call `update-coding-systems-internal'
 	;; if the released version of Emacs 21.1 is running.
-	(update-coding-systems-internal))
+	(if (fboundp 'update-coding-systems-internal)
+	    (update-coding-systems-internal)))
     (let ((alterable (and (charsetp bitmap-alterable-charset)
 			  (eq 2 (charset-dimension bitmap-alterable-charset))
 			  (eq 1 (charset-width bitmap-alterable-charset)))))
