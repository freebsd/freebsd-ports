--- lisp/help.el.orig	Mon Oct  1 16:01:24 2001
+++ lisp/help.el	Wed Apr 10 16:55:14 2002
@@ -593,8 +593,8 @@
     (load (expand-file-name
 	   ;; fns-XX.YY.ZZ.el does not work on DOS filesystem.
 	   (if (eq system-type 'ms-dos)
-	       "fns.el"
-	     (format "fns-%s.el" emacs-version))
+	       "fnsemcws.el"
+	     (format "fns-emcws-%s.el" emacs-version))
 	   exec-directory)
 	  ;; The file name fns-%s.el already has a .el extension.
 	  nil nil t)
