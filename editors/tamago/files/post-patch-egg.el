--- egg.el.orig	2012-08-04 09:27:19.000000000 +0900
+++ egg.el	2012-08-04 09:32:15.000000000 +0900
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
