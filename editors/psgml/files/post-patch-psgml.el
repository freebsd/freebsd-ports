--- psgml.el.orig	2015-11-12 14:12:58.516938000 +0900
+++ psgml.el	2015-11-12 14:13:03.188835000 +0900
@@ -52,7 +52,7 @@
 
 ;;; Code:
 
-(defconst psgml-version "1.3.2"
+(defconst psgml-version "1.4.0"
   "Version of psgml package.")
 
 (defconst psgml-maintainer-address "lenst@lysator.liu.se")
@@ -724,9 +724,9 @@
 
 (defun sgml-markup (entry text)
   (cons entry
-	(` (lambda ()
+	`(lambda ()
 	     (interactive)
-	     (sgml-insert-markup (, text))))))
+	     (sgml-insert-markup ,text))))
 
 (defun sgml-insert-markup (text)
   (let ((end (sgml-mouse-region))
@@ -1042,13 +1042,13 @@
 (defun sgml-compute-insert-dtd-items ()
   (loop for e in sgml-custom-dtd collect
         (vector (first e)
-                (` (sgml-doctype-insert (, (cadr e)) '(, (cddr e))))
+                `(sgml-doctype-insert ,(cadr e) ',(cddr e))
                 t)))
 
 (defun sgml-compute-custom-markup-items ()
   (loop for e in sgml-custom-markup collect
         (vector (first e)
-                (` (sgml-insert-markup  (, (cadr e))))
+                `(sgml-insert-markup  ,(cadr e))
                 t)))
 
 (defun sgml-build-custom-menus ()
@@ -1231,12 +1231,14 @@
     (make-local-variable 'text-property-default-nonsticky)
     ;; see `sgml-set-face-for':
     (add-to-list 'text-property-default-nonsticky '(face . t)))
-  (make-local-hook 'post-command-hook)
+  (if (fboundp 'make-local-hook)
+    (eval '(make-local-hook 'post-command-hook)))
   (add-hook 'post-command-hook 'sgml-command-post 'append 'local)
   (unless sgml-running-lucid
     ;; XEmacs 20.4 doesn't handle local activate-menubar-hook
     ;; it tries to call the function `t' when using the menubar
-    (make-local-hook 'activate-menubar-hook))
+    (if (fboundp 'make-local-hook)
+      (eval '(make-local-hook 'activate-menubar-hook))))
   (add-hook 'activate-menubar-hook 'sgml-update-all-options-menus
 	    nil 'local)
   (run-hooks 'text-mode-hook 'psgml-mode-hook)
