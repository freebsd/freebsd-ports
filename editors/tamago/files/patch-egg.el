--- egg.el.orig	2013-05-05 14:02:05.000000000 +0900
+++ egg.el	2013-05-05 14:02:05.000000000 +0900
@@ -167,16 +167,22 @@
 	  (setq egg-modefull-mode t)
 	  (its-define-select-keys egg-modefull-map))
       (setq egg-modeless-mode t))
-    (setq inactivate-current-input-method-function 'egg-mode)
+    (set (if (boundp 'deactivate-current-input-method-function)
+	     'deactivate-current-input-method-function
+	   'inactivate-current-input-method-function)
+	 'egg-mode)
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
+  (if (boundp 'deactivate-input-method)
+      deactivate-input-method
+    inactivate-input-method)
   (if (<= (minibuffer-depth) 1)
       (remove-hook 'minibuffer-exit-hook 'egg-exit-from-minibuffer)))
 
@@ -184,7 +190,10 @@
 
 (defun egg-self-insert-char ()
   (interactive)
-  (its-start last-command-char (and (eq last-command 'egg-use-context)
+  (its-start (if (boundp 'last-command-event)
+		 last-command-event
+	       last-command-char)
+	     (and (eq last-command 'egg-use-context)
 				    egg-context)))
 
 (defun egg-remove-all-text-properties (from to &optional object)
