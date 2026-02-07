--- lisp/riece-unread.el.orig	2011-04-04 06:47:48 UTC
+++ lisp/riece-unread.el
@@ -60,8 +60,13 @@
 (defvar riece-channel-list-unread-face 'riece-channel-list-unread-face)
 
 (unless (riece-facep 'riece-modeline-unread-face)
-  (make-face 'riece-modeline-unread-face
-	     "Face used for displaying unread channels in modeline.")
+  ;; In Emacs, set-face-doc-string is an alias to
+  ;; set-face-documentation, but we use the former since it is
+  ;; available in both Emacs and XEmacs.
+  (make-face 'riece-modeline-unread-face)
+  (set-face-doc-string
+   'riece-modeline-unread-face
+   "Face used for displaying unread channels in modeline.")
   (if (featurep 'xemacs)
       (set-face-parent 'riece-modeline-unread-face 'modeline))
   (set-face-foreground 'riece-modeline-unread-face
