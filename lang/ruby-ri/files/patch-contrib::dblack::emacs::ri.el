--- contrib/dblack/emacs/ri.el.orig	Fri Mar 16 12:25:28 2001
+++ contrib/dblack/emacs/ri.el	Thu Apr  5 23:01:04 2001
@@ -63,11 +63,11 @@
 ;; (autoload 'ri-show-term-composite-at-point "ri.el" "ri utility" t)
 ;;
 ;;;; Set this command to whatever you use to run ri:
-;; (setq ri-ri-command "/usr/local/bin/ri")
+(setq ri-ri-command "!!PREFIX!!/bin/ri")
 ;;
 ;;;; If you put Emacs.rb somewhere other than the main ri/op
 ;;;; directory, then change "Emacs" to "/full/path/to/Emacs.rb":
-;; (setq ri-emacsrb "Emacs")
+(setq ri-emacsrb "Emacs")
 ;;
 ;;;; These two global key bindings enable the instant ri lookup of a
 ;;;; term at point.  
@@ -82,7 +82,7 @@
 ;;; <ENTER> for convenience)
 ;;;
 ;;; (setq ri-key-quit "q")
-;;; bound to function ri-quit, which is probably quit-window)
+;;; bound to function ri-quit, which is probably delete-window)
 ;;;
 ;;; (setq ri-key-fnt "\C-i")
 ;;; find-next-term (TAB)
@@ -365,7 +365,7 @@
 (defun ri-quit()
   "Function bound to 'q' key in ri output buffer(s)"
   (interactive)
-  (quit-window))
+  (delete-window))
 
 ;;; Functions to find and show terms at or beyond point
 
