--- menudiag.el.orig	2001-01-28 03:53:13.000000000 +0900
+++ menudiag.el	2015-01-29 18:32:59.000000000 +0900
@@ -226,6 +226,9 @@
   (remove-hook 'minibuffer-setup-hook 'menudiag-minibuffer-hook)
   (setq menudiag-minibuffer-list (cons (current-buffer)
 				       menudiag-minibuffer-list))
+  (if (boundp 'deactivate-input-method)
+    (deactivate-input-method)
+    (inactivate-input-method))
   (buffer-disable-undo)
   (menudiag-receive-variables)
   (menudiag-beginning-of-items)
@@ -248,7 +251,7 @@
 			       (string-width (cadr menu)))))
   (add-hook 'minibuffer-setup-hook 'menudiag-minibuffer-hook)
   (unwind-protect
-      (progn
+      (let ((overriding-local-map menudiag-mode-map))
 	(read-from-minibuffer "" "" menudiag-mode-map)
 	(menudiag-receive-variables))
     (setq menudiag-minibuffer-list (cdr menudiag-minibuffer-list))
@@ -296,7 +299,7 @@
 (defun menudiag-goto-item ()
   (interactive)
   (menudiag-check-current-menu)
-  (let ((ch last-command-char)
+  (let ((ch last-command-event)
 	(n 0))
     (setq n (menudiag-char-to-item-num ch))
     (if (>= n (length menudiag-line))
@@ -503,7 +506,8 @@
   (make-local-variable 'inhibit-read-only)
   (setq buffer-read-only t
 	inhibit-read-only nil)
-  (make-local-hook 'post-command-hook)
+  (if (fboundp 'make-local-hook)
+    (eval '(make-local-hook 'post-command-hook)))
   (add-hook 'post-command-hook 'menudiag-selection-align-to-item nil t)
   (use-local-map menudiag-selection-map)
   (setq mode-name "Menudiag Selection")
@@ -595,10 +599,10 @@
       (set-buffer sel-buf)
       (setq completion-reference-buffer tmp-buf)
       (if event
-	  (mouse-choose-completion event)
+         (choose-completion event)
 	(choose-completion))
       (set-buffer tmp-buf)
-      (setq n (string-to-int (buffer-string))))
+      (setq n (string-to-number (buffer-string))))
     (pop-to-buffer org-buf)
     (while (and item-list (>= n (length (car item-list))))
       (setq l (1+ l)
@@ -619,7 +623,7 @@
   (unless (eq last-command 'menudiag-selection-goto)
     (setq menudiag-goto-number-list nil
 	  menudiag-original-point (point)))
-  (setq menudiag-goto-number-list (cons (- last-command-char ?0)
+  (setq menudiag-goto-number-list (cons (- last-command-event ?0)
 					menudiag-goto-number-list))
   (menudiag-selection-goto-internal))
 
