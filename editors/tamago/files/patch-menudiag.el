--- menudiag.el.orig	2001-01-28 03:53:13.000000000 +0900
+++ menudiag.el	2013-03-30 17:12:23.000000000 +0900
@@ -296,7 +296,7 @@
 (defun menudiag-goto-item ()
   (interactive)
   (menudiag-check-current-menu)
-  (let ((ch last-command-char)
+  (let ((ch last-command-event)
 	(n 0))
     (setq n (menudiag-char-to-item-num ch))
     (if (>= n (length menudiag-line))
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
@@ -619,7 +620,7 @@
   (unless (eq last-command 'menudiag-selection-goto)
     (setq menudiag-goto-number-list nil
 	  menudiag-original-point (point)))
-  (setq menudiag-goto-number-list (cons (- last-command-char ?0)
+  (setq menudiag-goto-number-list (cons (- last-command-event ?0)
 					menudiag-goto-number-list))
   (menudiag-selection-goto-internal))
 
