--- lisp/riece-highlight.el.orig	2011-04-04 06:43:24 UTC
+++ lisp/riece-highlight.el
@@ -194,8 +194,13 @@
   :group 'riece-highlight)
 
 (unless (riece-facep 'riece-modeline-current-face)
-  (make-face 'riece-modeline-current-face
-	     "Face used for displaying the current channel in modeline.")
+  ;; In Emacs, set-face-doc-string is an alias to
+  ;; set-face-documentation, but we use the former since it is
+  ;; available in both Emacs and XEmacs.
+  (make-face 'riece-modeline-current-face)
+  (set-face-doc-string
+   'riece-modeline-current-face
+   "Face used for displaying the current channel in modeline.")
   (if (featurep 'xemacs)
       (set-face-parent 'riece-modeline-current-face 'modeline))
   (set-face-foreground 'riece-modeline-current-face
