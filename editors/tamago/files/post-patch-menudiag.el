--- menudiag.el.orig	2001-01-28 03:53:13.000000000 +0900
+++ menudiag.el	2012-08-04 09:32:34.000000000 +0900
@@ -503,7 +503,8 @@
   (make-local-variable 'inhibit-read-only)
   (setq buffer-read-only t
 	inhibit-read-only nil)
-  (make-local-hook 'post-command-hook)
+  (if (fboundp 'make-local-hook)
+    (eval '(make-local-hook 'post-command-hook)))
   (add-hook 'post-command-hook 'menudiag-selection-align-to-item nil t)
   (use-local-map menudiag-selection-map)
   (setq mode-name "Menudiag Selection")
