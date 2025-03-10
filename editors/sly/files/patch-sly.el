--- sly.el.orig	2024-08-09 21:19:04 UTC
+++ sly.el
@@ -7487,24 +7487,35 @@ other non-nil value to unconditionally replace SLIME."
                  (const :tag "Do not replace SLIME" nil)
                  (const :tag "Do replace SLIME" t)))
 
-(cond
- ((or (not (memq 'slime-lisp-mode-hook lisp-mode-hook))
-      noninteractive
-      (prog1
-          (if (eq sly-replace-slime 'ask)
-              (y-or-n-p "[sly] SLIME detected in `lisp-mode-hook', causes keybinding conflicts.  Remove it for this Emacs session?")
-            sly-replace-slime)
-        (warn "To restore SLIME in this session, customize `lisp-mode-hook'
-and replace `sly-editing-mode' with `slime-lisp-mode-hook'.")))
-  (remove-hook 'lisp-mode-hook 'slime-lisp-mode-hook)
+(let ((proceed-p
+       (if noninteractive
+           (lambda ()
+             (if (eq sly-replace-slime 'ask)
+                 t
+               sly-replace-slime))
+         (let (asked resp)
+           (lambda ()
+             (unless asked
+               (setq resp
+                     (if (eq sly-replace-slime 'ask)
+                         (y-or-n-p
+                          (eval-when-compile
+                            (concat "[sly] SLIME detected. Try to disable it "
+                                    "for this Emacs session?")))
+                       sly-replace-slime)
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
-        (unless sly-editing-mode (sly-editing-mode 1))
-        (ignore-errors (and (featurep 'slime) (funcall 'slime-mode -1)))))))
- (t
-  (warn
-   "`sly.el' loaded OK. To use SLY, customize `lisp-mode-hook' and remove `slime-lisp-mode-hook'.")))
+        (when (and (boundp 'slime-mode) slime-mode (funcall proceed-p))
+          (ignore-errors (funcall 'slime-mode -1)))
+        (sly-editing-mode 1)))))
 
 (provide 'sly)
 
