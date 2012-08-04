--- psgml.el.orig	2012-08-04 11:43:47.000000000 +0900
+++ psgml.el	2012-08-04 11:43:51.000000000 +0900
@@ -381,7 +381,7 @@
 (put 'sgml-system-path 'sgml-type 'file-list)
 
 (defvar sgml-public-map (or (sgml-parse-colon-path (getenv "SGML_PATH"))
-			    '("%S" "@prefix@/share/sgml/%o/%c/%d" ))
+			    '("%S" "/usr/local/share/sgml/%o/%c/%d" ))
   "*Mapping from public identifiers to file names.
 This is a list of possible file names.  To find the file for a public
 identifier the elements of the list are used one at the time from the
@@ -407,15 +407,15 @@
 (defvar sgml-catalog-files (or (delete nil
 				       (sgml-parse-colon-path
 					(getenv "SGML_CATALOG_FILES")))
-			       '("catalog" "@prefix@/share/sgml/catalog"
-			         "@prefix@/share/xml/catalog"))
+			       '("catalog" "/usr/local/share/sgml/catalog"
+			         "/usr/local/share/xml/catalog"))
   "*List of catalog entry files.
 The files are in the format defined in the SGML Open Draft Technical
 Resolution on Entity Management.")
 (put 'sgml-catalog-files 'sgml-type 'file-list)
 
-(defvar sgml-ecat-files '("ECAT" "~/sgml/ECAT" "@prefix@/share/sgml/ECAT"
-			  "@prefix@/share/xml/ECAT")
+(defvar sgml-ecat-files '("ECAT" "~/sgml/ECAT" "/usr/local/share/sgml/ECAT"
+			  "/usr/local/share/xml/ECAT")
   "*List of catalog files for PSGML.")
 (put 'sgml-ecat-files 'sgml-type 'file-list)
 
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
