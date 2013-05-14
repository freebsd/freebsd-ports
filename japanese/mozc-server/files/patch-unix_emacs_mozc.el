--- unix/emacs/mozc.el.orig	2013-03-29 13:33:43.000000000 +0900
+++ unix/emacs/mozc.el	2013-05-05 17:27:24.000000000 +0900
@@ -1755,29 +1755,36 @@
 
 (require 'mule)
 
-(defun mozc-leim-activate (input-method)
+(defun mozc-leim-activate (&rest input-method)
   "Activate mozc-mode via LEIM.
 INPUT-METHOD is not used."
-  (setq inactivate-current-input-method-function 'mozc-leim-inactivate)
+  (set
+    (if (boundp 'deactivate-current-input-method-function)
+        'deactivate-current-input-method-function
+      'inactivate-current-input-method-function)
+     'mozc-leim-deactivate)
   (mozc-mode t))
 
-(defun mozc-leim-inactivate ()
-  "Inactivate mozc-mode via LEIM."
+(defun mozc-leim-deactivate ()
+  "Deactivate mozc-mode via LEIM."
   (mozc-mode nil))
 
-(defcustom mozc-leim-title "[Mozc]"
-  "Mode line string shown when mozc-mode is enabled.
-This indicator is not shown when you don't use LEIM."
-  :type '(choice (const :tag "No indicator" nil)
-                 (string :tag "Show an indicator"))
-  :group 'mozc)
+;; Defined in leim-list.el
 
-(register-input-method
- "japanese-mozc"
- "Japanese"
- 'mozc-leim-activate
- mozc-leim-title
- "Japanese input method with Mozc/Google Japanese Input.")
+;; (defcustom mozc-leim-title "[Mozc]"
+;;  "Mode line string shown when mozc-mode is enabled.
+;; This indicator is not shown when you don't use LEIM."
+;;  :type '(choice (const :tag "No indicator" nil)
+;;                 (string :tag "Show an indicator"))
+;;  :group 'mozc)
+
+;;
+;; (register-input-method
+;;  "japanese-mozc"
+;;  "Japanese"
+;;  'mozc-leim-activate
+;;  mozc-leim-title
+;; "Japanese input method with Mozc/Google Japanese Input.")
 
 
 
