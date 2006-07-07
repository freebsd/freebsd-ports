Index: lisp/uudecode.el
===================================================================
RCS file: /pack/xemacscvs/XEmacs/packages/xemacs-packages/gnus/lisp/uudecode.el,v
retrieving revision 1.5
diff -u -r1.5 uudecode.el
--- lisp/gnus/uudecode.el	2006/03/16 04:18:08	1.5
+++ lisp/gnus/uudecode.el	2006/07/07 09:31:58
@@ -100,7 +100,8 @@
 			      (make-temp-name "uu")
 			      uudecode-temporary-file-directory))))
 	(let ((cdir default-directory)
-	      default-process-coding-system)
+	      (coding-system-for-read 'binary)
+	      (coding-system-for-write 'binary))
 	  (unwind-protect
 	      (with-temp-buffer
 		(insert "begin 600 " (file-name-nondirectory tempfile) "\n")
Index: lisp/binhex.el
===================================================================
RCS file: /pack/xemacscvs/XEmacs/packages/xemacs-packages/gnus/lisp/binhex.el,v
retrieving revision 1.5
diff -u -r1.5 binhex.el
--- lisp/gnus/binhex.el	2006/03/16 04:17:41	1.5
+++ lisp/gnus/binhex.el	2006/07/07 09:32:00
@@ -289,7 +289,9 @@
     (save-excursion
       (goto-char start)
       (when (re-search-forward binhex-begin-line nil t)
-	(let ((cdir default-directory) default-process-coding-system)
+	(let ((cdir default-directory)
+	      (coding-system-for-read 'binary)
+	      (coding-system-for-write 'binary))
 	  (unwind-protect
 	      (progn
 		(set-buffer (setq work-buffer
