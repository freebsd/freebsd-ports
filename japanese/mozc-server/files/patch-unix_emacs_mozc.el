--- unix/emacs/mozc.el.orig	2014-08-31 03:35:19.000000000 +0900
+++ unix/emacs/mozc.el	2014-08-31 03:52:11.000000000 +0900
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
 
 
 
