--- contrib/dblack/emacs/ri.el.orig	Fri Mar 16 12:25:28 2001
+++ contrib/dblack/emacs/ri.el	Sat Apr  7 02:55:55 2001
@@ -82,7 +82,10 @@
 ;;; <ENTER> for convenience)
 ;;;
 ;;; (setq ri-key-quit "q")
-;;; bound to function ri-quit, which is probably quit-window)
+;;; bound to function ri-quit, which is probably delete-window)
+;;;
+;;; (setq ri-key-kill "Q")
+;;; bound to function ri-kill, which is probably kill-buffer & delete-window)
 ;;;
 ;;; (setq ri-key-fnt "\C-i")
 ;;; find-next-term (TAB)
@@ -233,9 +236,14 @@
 (defvar ri-switch-to-ri-buffer t)
 (defvar ri-read-only t)
 
+;; Locations
+(defvar ri-ri-command "/usr/local/bin/ri")
+(defvar ri-emacsrb "Emacs")
+
 ;; Key bindings
 (defvar ri-key-stcap "\C-m")
 (defvar ri-key-quit "q")
+(defvar ri-key-kill "Q")
 (defvar ri-key-fnt "\C-i")
 (defvar ri-key-fpt "\M-\C-i")
 
@@ -276,6 +284,7 @@
        (and ri-read-only
 	    (setq buffer-read-only t))
        (local-set-key ri-key-quit 'ri-quit)
+       (local-set-key ri-key-kill 'ri-kill)
        (local-set-key ri-key-stcap 'ri-show-term-composite-at-point)
        (local-set-key ri-key-fnt 'ri-find-next-term)
        (local-set-key ri-key-fpt 'ri-find-previous-term))
@@ -365,7 +374,13 @@
 (defun ri-quit()
   "Function bound to 'q' key in ri output buffer(s)"
   (interactive)
-  (quit-window))
+  (delete-window))
+
+(defun ri-kill()
+  "Function bound to 'Q' key in ri output buffer(s)"
+  (interactive)
+  (kill-buffer nil)
+  (delete-window))
 
 ;;; Functions to find and show terms at or beyond point
 
