--- src/unix/emacs/mozc.el.orig	2015-02-15 04:18:31.000000000 +0900
+++ src/unix/emacs/mozc.el	2015-02-19 04:01:46.000000000 +0900
@@ -1538,7 +1538,7 @@
 
 ;;;; Communication with Mozc server through the helper process
 
-(defvar mozc-helper-program-name "mozc_emacs_helper"
+(defvar mozc-helper-program-name "%%PREFIX%%/libexec/mozc_emacs_helper"
   "Helper program's name or path to the helper program.
 The helper program helps Emacs communicate with Mozc server,
 which doesn't understand S-expression.")
@@ -1973,12 +1973,12 @@
   "Deactivate function `mozc-mode' via LEIM."
   (mozc-mode nil))
 
-(defcustom mozc-leim-title "[Mozc]"
-  "Mode line string shown when function `mozc-mode' is enabled.
-This indicator is not shown when you don't use LEIM."
-  :type '(choice (const :tag "No indicator" nil)
-                 (string :tag "Show an indicator"))
-  :group 'mozc)
+;;(defcustom mozc-leim-title "[Mozc]"
+;;  "Mode line string shown when function `mozc-mode' is enabled.
+;;This indicator is not shown when you don't use LEIM."
+;;  :type '(choice (const :tag "No indicator" nil)
+;;                 (string :tag "Show an indicator"))
+;;  :group 'mozc)
 
 (defun mozc-leim-register-input-method ()
   "Register function `mozc-mode' as an input method of LEIM.
@@ -1994,10 +1994,10 @@
 ;; Register mozc-mode as an input method after the init file has been read
 ;; so the user has a chance to specify `mozc-leim-title' in the init file
 ;; after loading this file.
-(add-hook 'emacs-startup-hook #'mozc-leim-register-input-method)
+;;(add-hook 'emacs-startup-hook #'mozc-leim-register-input-method)
 ;; In the case that `emacs-startup-hook' has already been run, especially
 ;; when the user loads this file interactively, register immediately.
-(mozc-leim-register-input-method)
+;;(mozc-leim-register-input-method)
 
 
 
