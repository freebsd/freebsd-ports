--- sly-asdf.el.orig	2023-05-26 11:13:10 UTC
+++ sly-asdf.el
@@ -355,10 +355,5 @@ in the directory of the current buffer."
 
 
 
-;;;###autoload
-(with-eval-after-load 'sly
-  (add-to-list 'sly-contribs 'sly-asdf 'append))
-
-
 (provide 'sly-asdf)
 ;;; sly-asdf.el ends here
