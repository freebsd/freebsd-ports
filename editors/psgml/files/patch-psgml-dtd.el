--- psgml-dtd.el.orig	2005-03-06 01:23:40.000000000 +0900
+++ psgml-dtd.el	2012-08-04 11:56:25.000000000 +0900
@@ -93,12 +93,12 @@
 (defmacro sgml-for-all-final-states (s dfa &rest forms)
   "For all final states S in DFA do FORMS.
 Syntax: var dfa-expr &body forms"
-  (` (let ((L-states (sgml-some-states-of (, dfa)))
-	   (, s))
+  `(let ((L-states (sgml-some-states-of ,dfa))
+	   ,s)
        (while L-states
-	 (when (sgml-state-final-p (setq (, s) (car L-states)))
-	   (,@ forms))
-	 (setq L-states (cdr L-states))))))
+	 (when (sgml-state-final-p (setq ,s (car L-states)))
+	   ,@forms)
+	 (setq L-states (cdr L-states)))))
 
 (put 'sgml-for-all-final-states 'lisp-indent-hook 2)
 (put 'sgml-for-all-final-states 'edebug-form-hook '(symbolp &rest form))
@@ -217,7 +217,7 @@
 (defun sgml-make-pcdata ()
   (sgml-make-* (sgml-make-primitive-content-token sgml-pcdata-token)))
 
-(defun sgml-reduce-, (l)
+(defun sgml-reduce-\, (l)
   (while (cdr l)
     (setcar (cdr l)
 	    (sgml-make-conc (car l) (cadr l)))
@@ -279,7 +279,7 @@
 	  (sgml-parse-delim "CRO" (digit nmstart))
 	(sgml-parse-delim "CRO" (digit)))
       (prog1 (if (sgml-is-delim "NULL" digit)
-		 (string-to-int (sgml-check-nametoken))
+		 (string-to-number (sgml-check-nametoken))
 	       (let ((spec (sgml-check-name)))
 		 (or (cdr (assoc spec '(("RE" . 10)
 					("RS" . 1)
@@ -336,7 +336,7 @@
 (defsubst sgml-parse-connector ()
   (sgml-skip-ps)
   (cond ((sgml-parse-delim "SEQ")
-	 (function sgml-reduce-,))
+	 (function sgml-reduce-\,))
 	((sgml-parse-delim "OR")
 	 (function sgml-reduce-|))
 	((sgml-parse-delim "AND")
@@ -884,10 +884,10 @@
 FORMS should produce the binary coding of element in VAR."
   (let ((var (car loop-c))
 	(seq (cadr loop-c)))
-    (` (let ((seq (, seq)))
+    `(let ((seq ,seq))
 	 (sgml-code-number (length seq))
-	 (loop for (, var) in seq
-	       do (,@ body))))))
+	 (loop for ,var in seq
+	       do ,@body))))
 
 (put 'sgml-code-sequence 'lisp-indent-hook 1)
 (put 'sgml-code-sequence 'edbug-forms-hook '(sexp &rest form))
