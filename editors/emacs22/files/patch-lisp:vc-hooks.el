--- lisp/vc-hooks.el.orig	Mon Nov 12 23:37:38 2001
+++ lisp/vc-hooks.el	Tue Nov 13 12:56:08 2001
@@ -475,10 +475,9 @@
   (if regexp
       (concat (regexp-quote (file-name-nondirectory file))
               "\\.~[0-9.]+" (unless manual "\\.") "~")
-    (expand-file-name (concat (file-name-nondirectory file) 
-                              ".~" (or rev (vc-workfile-version file)) 
-                              (unless manual ".") "~")
-                      (file-name-directory file))))
+    (concat (make-backup-file-name-1 file)
+	    ".~" (or rev (vc-workfile-version file))
+	    (unless manual ".") "~")))
 
 (defun vc-delete-automatic-version-backups (file)
   "Delete all existing automatic version backups for FILE."
@@ -509,6 +508,7 @@
 	 (vc-up-to-date-p file)
 	 (eq (vc-checkout-model file) 'implicit)
 	 (vc-call make-version-backups-p file)
+	 vc-make-backup-files
          (vc-make-version-backup file))))
 
 (defun vc-after-save ()
