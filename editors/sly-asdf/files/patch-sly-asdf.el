--- sly-asdf.el.orig	2021-03-08 03:32:35 UTC
+++ sly-asdf.el
@@ -354,10 +354,5 @@ in the directory of the current buffer."
 
 
 
-;;;###autoload
-(with-eval-after-load 'sly
-  (add-to-list 'sly-contribs 'sly-asdf 'append))
-
-
 (provide 'sly-asdf)
 ;;; sly-asdf.el ends here
