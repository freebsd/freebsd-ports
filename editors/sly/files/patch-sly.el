--- sly.el.orig	2021-01-14 09:12:56 UTC
+++ sly.el
@@ -7463,22 +7463,30 @@ can be found."
 ;;;###autoload
 (add-hook 'lisp-mode-hook 'sly-editing-mode)
 
-(cond
- ((or (not (memq 'slime-lisp-mode-hook lisp-mode-hook))
-      noninteractive
-      (prog1
-          (y-or-n-p "[sly] SLIME detected in `lisp-mode-hook', causes keybinding conflicts.  Remove it for this Emacs session?")
-        (warn "To restore SLIME in this session, customize `lisp-mode-hook'
-and replace `sly-editing-mode' with `slime-lisp-mode-hook'.")))
-  (remove-hook 'lisp-mode-hook 'slime-lisp-mode-hook)
+(let ((proceed-p
+       (if noninteractive
+           (lambda () t)
+         (let (asked resp)
+           (lambda ()
+             (unless asked
+               (setq resp
+                     (y-or-n-p
+                      (eval-when-compile
+                        (concat "[sly] SLIME detected. Try to disable it "
+                                "for this Emacs session?")))
+                     asked t))
+             resp)))))
+  (when (and (memq 'slime-lisp-mode-hook lisp-mode-hook)
+             (funcall proceed-p))
+    (warn "To restore SLIME in this session, customize `lisp-mode-hook' and
+replace `sly-editing-mode' with `slime-lisp-mode-hook'.")
+    (remove-hook 'lisp-mode-hook 'slime-lisp-mode-hook))
   (dolist (buffer (buffer-list))
     (with-current-buffer buffer
       (when (eq major-mode 'lisp-mode)
-        (sly-editing-mode 1)
-        (ignore-errors (funcall 'slime-mode -1))))))
- (t
-  (warn
-   "`sly.el' loaded OK. To use SLY, customize `lisp-mode-hook' and remove `slime-lisp-mode-hook'.")))
+        (when (and (boundp 'slime-mode) slime-mode (funcall proceed-p))
+          (ignore-errors (funcall 'slime-mode -1)))
+        (sly-editing-mode 1)))))
 
 (provide 'sly)
 
