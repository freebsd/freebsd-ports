--- its.el.orig	2015-01-31 19:24:09.000000000 +0900
+++ its.el	2015-01-31 19:25:52.000000000 +0900
@@ -397,7 +397,7 @@
 (defun its-self-insert-char ()
   (interactive)
   (let ((inhibit-read-only t)
-	(key last-command-char)
+	(key last-command-event)
 	(cursor (get-text-property (point) 'its-cursor))
 	(syl (get-text-property (1- (point)) 'its-syl)))
     (cond
@@ -1264,7 +1264,7 @@
   (interactive "P")
   (let ((syl (and (null (get-text-property (point) 'its-cursor))
 		  (get-text-property (1- (point)) 'its-syl))))
-    (if (its-keyseq-acceptable-p (vector last-command-char) syl)
+    (if (its-keyseq-acceptable-p (vector last-command-event) syl)
 	(its-self-insert-char)
       (its-kick-convert-region n))))
 
@@ -1554,7 +1554,8 @@
   (with-output-to-temp-buffer "*Help*"
     (princ "ITS mode:\n")
     (princ (documentation 'its-mode))
-    (help-setup-xref (cons #'help-xref-mode (current-buffer)) (interactive-p))))
+    (help-setup-xref (cons #'help-xref-mode (current-buffer))
+      (called-interactively-p 'interactive))))
 
 ;; The `point-left' hook function will never be called in Emacs 21.2.50
 ;; when the command `next-line' is used in the last line of a buffer
