--- psgml-edit.el.orig2	Tue Feb 21 07:02:29 2006
+++ psgml-edit.el	Tue Feb 21 07:08:59 2006
@@ -1876,18 +1876,22 @@
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
