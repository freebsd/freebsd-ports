--- egg.el.orig	2013-04-23 16:13:43.000000000 +0900
+++ egg.el	2013-04-23 16:15:26.000000000 +0900
@@ -167,16 +167,17 @@
 	  (setq egg-modefull-mode t)
 	  (its-define-select-keys egg-modefull-map))
       (setq egg-modeless-mode t))
-    (setq inactivate-current-input-method-function 'egg-mode)
+    (setq deactivate-current-input-method-function 'egg-mode)
     (setq describe-current-input-method-function 'egg-help)
-    (make-local-hook 'input-method-activate-hook)
+    (if (fboundp 'make-local-hook)
+      (eval '(make-local-hook 'input-method-activate-hook)))
     (add-hook 'input-method-activate-hook 'its-set-mode-line-title nil t)
     (if (eq (selected-window) (minibuffer-window))
 	(add-hook 'minibuffer-exit-hook 'egg-exit-from-minibuffer))
     (run-hooks 'egg-mode-hook)))
 
 (defun egg-exit-from-minibuffer ()
-  (inactivate-input-method)
+  (deactivate-input-method)
   (if (<= (minibuffer-depth) 1)
       (remove-hook 'minibuffer-exit-hook 'egg-exit-from-minibuffer)))
 
@@ -184,7 +185,7 @@
 
 (defun egg-self-insert-char ()
   (interactive)
-  (its-start last-command-char (and (eq last-command 'egg-use-context)
+  (its-start last-command-event (and (eq last-command 'egg-use-context)
 				    egg-context)))
 
 (defun egg-remove-all-text-properties (from to &optional object)
