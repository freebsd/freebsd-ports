--- lisp/riece-history.el.orig	2011-04-04 06:24:37 UTC
+++ lisp/riece-history.el
@@ -65,8 +65,13 @@
 (defvar riece-channel-list-history-face 'riece-channel-list-history-face)
 
 (unless (riece-facep 'riece-modeline-history-face)
-  (make-face 'riece-modeline-history-face
-	     "Face used for displaying history channels in modeline.")
+  ;; In Emacs, set-face-doc-string is an alias to
+  ;; set-face-documentation, but we use the former since it is
+  ;; available in both Emacs and XEmacs.
+  (make-face 'riece-modeline-history-face)
+  (set-face-doc-string
+   'riece-modeline-history-face
+   "Face used for displaying history channels in modeline.")
   (if (featurep 'xemacs)
       (set-face-parent 'riece-modeline-history-face 'modeline))
   (set-face-foreground 'riece-modeline-history-face
