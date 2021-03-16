--- sly-quicklisp.el.orig	2020-07-07 16:35:00 UTC
+++ sly-quicklisp.el
@@ -91,10 +91,5 @@ in `sly-editing-mode-hook', i.e. lisp files."
                                        sly-quicklisp--enabled-dists)
                              "NO QL dists reported so far. Load a system using `sly-quickload'")))
 
-;;; Automatically add ourselves to `sly-contribs' when this file is loaded
-;;;###autoload
-(with-eval-after-load 'sly
-  (add-to-list 'sly-contribs 'sly-quicklisp 'append))
-
 (provide 'sly-quicklisp)
 ;;; sly-quicklisp.el ends here
