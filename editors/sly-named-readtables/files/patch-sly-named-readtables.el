--- sly-named-readtables.el.orig	2019-10-13 21:38:43 UTC
+++ sly-named-readtables.el
@@ -107,9 +107,5 @@
 (defun sly-named-readtables--pass-readtable ()
   (list :named-readtable (sly-named-readtables--grok-current-table)))
 
-;;;###autoload
-(with-eval-after-load 'sly
-  (add-to-list 'sly-contribs 'sly-named-readtables 'append))
-
 (provide 'sly-named-readtables)
 ;;; sly-named-readtables.el ends here
