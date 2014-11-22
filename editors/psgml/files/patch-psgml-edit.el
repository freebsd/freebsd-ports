--- psgml-edit.el.orig	2013-06-03 13:44:59.000000000 +0900
+++ psgml-edit.el	2013-06-03 14:13:25.000000000 +0900
@@ -185,7 +185,9 @@
     (goto-char (sgml-element-start element))
     (delete-char (sgml-element-stag-len element))
     (insert (sgml-delim "STAGO")
-            (sgml-general-insert-case gi)
+            (if (symbolp gi)
+                (sgml-general-insert-case (symbol-name gi))
+              (sgml-general-insert-case gi))
             tagc)
     (let* ((newel (sgml-find-context-of (point)))
 	   (newattlist (sgml-element-attlist newel))
@@ -1870,24 +1872,28 @@
    (invert
     (or (looking-at "&#\\([0-9]+\\)[;\n]?")
 	(error "No character reference after point"))
-    (let ((c (string-to-int (buffer-substring (match-beginning 1)
+    (let ((c (string-to-number (buffer-substring (match-beginning 1)
 					      (match-end 1)))))
       (delete-region (match-beginning 0)
 		     (match-end 0))
       (if (fboundp 'decode-char)	; Emacs 21, Mule-UCS
 	  (setq c (decode-char 'ucs c))
+	(if (fboundp 'ucs-to-char)
+	    (setq c (ucs-to-char c))
 	;; Else have to assume 8-bit character.
-	(if (fboundp 'unibyte-char-to-multibyte) ; Emacs 20
-	    (setq c (unibyte-char-to-multibyte c))))
+	  (if (fboundp 'unibyte-char-to-multibyte) ; Emacs 20
+	      (setq c (unibyte-char-to-multibyte c)))))
       (insert c)))
    ;; Convert character to &#nn;
    (t
     (let ((c (following-char)))
       (delete-char 1)
-      (if (fboundp 'encode-char)
-	  (setq c (encode-char c 'ucs))
-	(if (fboundp 'multibyte-char-to-unibyte)
-	    (setq c (multibyte-char-to-unibyte c))))
+      (if (fboundp 'char-to-ucs)
+	  (setq c (char-to-ucs c))
+	(if (fboundp 'encode-char)
+	    (setq c (encode-char c 'ucs))
+	  (if (fboundp 'multibyte-char-to-unibyte)
+	      (setq c (multibyte-char-to-unibyte c)))))
       (insert (format "&#%d;" c))))))
 
 (defun sgml-expand-entity-reference ()
