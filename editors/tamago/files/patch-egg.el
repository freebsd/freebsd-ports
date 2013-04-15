--- egg.el.orig	2013-03-30 17:08:47.000000000 +0900
+++ egg.el	2013-03-30 17:11:22.000000000 +0900
@@ -169,7 +169,8 @@
       (setq egg-modeless-mode t))
     (setq inactivate-current-input-method-function 'egg-mode)
     (setq describe-current-input-method-function 'egg-help)
-    (make-local-hook 'input-method-activate-hook)
+    (if (fboundp 'make-local-hook)
+      (eval '(make-local-hook 'input-method-activate-hook)))
     (add-hook 'input-method-activate-hook 'its-set-mode-line-title nil t)
     (if (eq (selected-window) (minibuffer-window))
 	(add-hook 'minibuffer-exit-hook 'egg-exit-from-minibuffer))
@@ -184,7 +185,7 @@
 
 (defun egg-self-insert-char ()
   (interactive)
-  (its-start last-command-char (and (eq last-command 'egg-use-context)
+  (its-start last-command-event (and (eq last-command 'egg-use-context)
 				    egg-context)))
 
 (defun egg-remove-all-text-properties (from to &optional object)
