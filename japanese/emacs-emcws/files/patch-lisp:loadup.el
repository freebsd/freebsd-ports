--- lisp/loadup.el.orig	Wed Apr 10 16:53:14 2002
+++ lisp/loadup.el	Wed Apr 10 16:55:48 2002
@@ -264,7 +264,7 @@
       (if (memq system-type '(ms-dos windows-nt))
 	  (setq name (expand-file-name
 		      (if (fboundp 'x-create-frame) "DOC-X" "DOC") "../etc"))
-	(setq name (concat (expand-file-name "../etc/DOC-") name))
+	(setq name (concat (expand-file-name "../etc/DOC-EMCWS-") name))
 	(if (file-exists-p name)
 	    (delete-file name))
 	(copy-file (expand-file-name "../etc/DOC") name t))
@@ -300,11 +300,11 @@
 		    (expand-file-name
 		     (cond
 		      ((eq system-type 'ms-dos)
-		       "../lib-src/fns.el")
+		       "../lib-src/fnsemcws.el")
 		      ((eq system-type 'windows-nt)
-		       (format "../../../lib-src/fns-%s.el" emacs-version))
+		       (format "../../../lib-src/fns-emcws-%s.el" emacs-version))
 		      (t
-		       (format "../lib-src/fns-%s.el" emacs-version)))
+		       (format "../lib-src/fns-emcws-%s.el" emacs-version)))
 		     invocation-directory))
       (erase-buffer)
       (setq load-history nil))
