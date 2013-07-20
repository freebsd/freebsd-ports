--- unix/emacs/mozc.el.orig	2013-07-17 11:37:50.000000000 +0900
+++ unix/emacs/mozc.el	2013-07-19 22:36:17.000000000 +0900
@@ -1834,19 +1834,20 @@
   "Deactivate mozc-mode via LEIM."
   (mozc-mode nil))
 
-(defcustom mozc-leim-title "[Mozc]"
-  "Mode line string shown when mozc-mode is enabled.
-This indicator is not shown when you don't use LEIM."
-  :type '(choice (const :tag "No indicator" nil)
-                 (string :tag "Show an indicator"))
-  :group 'mozc)
+;; defined in leim-list.el
+;; (defcustom mozc-leim-title "[Mozc]"
+;;   "Mode line string shown when mozc-mode is enabled.
+;; This indicator is not shown when you don't use LEIM."
+;;  :type '(choice (const :tag "No indicator" nil)
+;;                 (string :tag "Show an indicator"))
+;;  :group 'mozc)
 
-(register-input-method
- "japanese-mozc"
- "Japanese"
- #'mozc-leim-activate
- mozc-leim-title
- "Japanese input method with Mozc/Google Japanese Input.")
+;; (register-input-method
+;; "japanese-mozc"
+;; "Japanese"
+;; #'mozc-leim-activate
+;; mozc-leim-title
+;; "Japanese input method with Mozc/Google Japanese Input.")
 
 
 
