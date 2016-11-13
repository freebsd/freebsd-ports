Index: pccl.el
===================================================================
--- pccl.el.orig	2005-07-06 02:08:53 UTC
+++ pccl.el
@@ -27,138 +27,138 @@
 (require 'broken)
 
 (broken-facility ccl-usable
-  "Emacs has not CCL."
-  (and (featurep 'mule)
-       (if (featurep 'xemacs)
-           (>= emacs-major-version 21)
-         (>= emacs-major-version 19))))
+		 "Emacs has not CCL."
+		 (and (featurep 'mule)
+		      (if (featurep 'xemacs)
+			  (>= emacs-major-version 21)
+			(>= emacs-major-version 19))))
 
 (unless-broken ccl-usable
-  (require 'advice)
+	       (require 'advice)
 
-  (if (featurep 'mule)
-      (progn
-	(require 'ccl)
-	(if (featurep 'xemacs)
-            (if (>= emacs-major-version 21)
-                ;; for XEmacs 21 with mule
-                (require 'pccl-20))
-          (if (>= emacs-major-version 20)
-              ;; for Emacs 20
-              (require 'pccl-20)
-            ;; for Mule 2.*
-            (require 'pccl-om)))))
+	       (if (featurep 'mule)
+		   (progn
+		     (require 'ccl)
+		     (if (featurep 'xemacs)
+			 (if (>= emacs-major-version 21)
+			     ;; for XEmacs 21 with mule
+			     (require 'pccl-20))
+		       (if (>= emacs-major-version 20)
+			   ;; for Emacs 20
+			   (require 'pccl-20)
+			 ;; for Mule 2.*
+			 (require 'pccl-om)))))
 
-  (static-if (or (featurep 'xemacs) (< emacs-major-version 21))
-    (defadvice define-ccl-program
-      (before accept-long-ccl-program activate)
-      "When CCL-PROGRAM is too long, internal buffer is extended automatically."
-      (let ((try-ccl-compile t)
-	    (prog (eval (ad-get-arg 1))))
-	(ad-set-arg 1 (` '(, prog)))
-	(while try-ccl-compile
-	  (setq try-ccl-compile nil)
-	  (condition-case sig
-	      (ccl-compile prog)
-	    (args-out-of-range
-	     (if (and (eq (car (cdr sig)) ccl-program-vector)
-		      (= (car (cdr (cdr sig))) (length ccl-program-vector)))
-		 (setq ccl-program-vector
-		       (make-vector (* 2 (length ccl-program-vector)) 0)
-		       try-ccl-compile t)
-	       (signal (car sig) (cdr sig)))))))))
+	       (static-if (or (featurep 'xemacs) (< emacs-major-version 21))
+			  (defadvice define-ccl-program
+			    (before accept-long-ccl-program activate)
+			    "When CCL-PROGRAM is too long, internal buffer is extended automatically."
+			    (let ((try-ccl-compile t)
+				  (prog (eval (ad-get-arg 1))))
+			      (ad-set-arg 1 `',prog)
+			      (while try-ccl-compile
+				(setq try-ccl-compile nil)
+				(condition-case sig
+				    (ccl-compile prog)
+				  (args-out-of-range
+				   (if (and (eq (car (cdr sig)) ccl-program-vector)
+					    (= (car (cdr (cdr sig))) (length ccl-program-vector)))
+				       (setq ccl-program-vector
+					     (make-vector (* 2 (length ccl-program-vector)) 0)
+					     try-ccl-compile t)
+				     (signal (car sig) (cdr sig)))))))))
 
-  (static-when (and (not (featurep 'xemacs)) (< emacs-major-version 21))
-    (defun-maybe transform-make-coding-system-args (name type &optional doc-string props)
-      "For internal use only.
+	       (static-when (and (not (featurep 'xemacs)) (< emacs-major-version 21))
+			    (defun-maybe transform-make-coding-system-args (name type &optional doc-string props)
+			      "For internal use only.
 Transform XEmacs style args for `make-coding-system' to Emacs style.
 Value is a list of transformed arguments."
-      (let ((mnemonic (string-to-char (or (plist-get props 'mnemonic) "?")))
-	    (eol-type (plist-get props 'eol-type))
-	    properties tmp)
-	(cond
-	 ((eq eol-type 'lf) (setq eol-type 'unix))
-	 ((eq eol-type 'crlf) (setq eol-type 'dos))
-	 ((eq eol-type 'cr) (setq eol-type 'mac)))
-	(if (setq tmp (plist-get props 'post-read-conversion))
-	    (setq properties (plist-put properties 'post-read-conversion tmp)))
-	(if (setq tmp (plist-get props 'pre-write-conversion))
-	    (setq properties (plist-put properties 'pre-write-conversion tmp)))
-	(cond
-	 ((eq type 'shift-jis)
-	  (` ((, name) 1 (, mnemonic) (, doc-string)
-	      nil (, properties) (, eol-type))))
-	 ((eq type 'iso2022) ; This is not perfect.
-	  (if (plist-get props 'escape-quoted)
-	      (error "escape-quoted is not supported: %S"
-		     (` ((, name) (, type) (, doc-string) (, props)))))
-	  (let ((g0 (plist-get props 'charset-g0))
-		(g1 (plist-get props 'charset-g1))
-		(g2 (plist-get props 'charset-g2))
-		(g3 (plist-get props 'charset-g3))
-		(use-roman
-		 (and
-		  (eq (cadr (assoc 'latin-jisx0201
-				   (plist-get props 'input-charset-conversion)))
-		      'ascii)
-		  (eq (cadr (assoc 'ascii
-				   (plist-get props 'output-charset-conversion)))
-		      'latin-jisx0201)))
-		(use-oldjis
-		 (and
-		  (eq (cadr (assoc 'japanese-jisx0208-1978
-				   (plist-get props 'input-charset-conversion)))
-		      'japanese-jisx0208)
-		  (eq (cadr (assoc 'japanese-jisx0208
-				   (plist-get props 'output-charset-conversion)))
-		      'japanese-jisx0208-1978))))
-	    (if (charsetp g0)
-		(if (plist-get props 'force-g0-on-output)
-		    (setq g0 (` (nil (, g0))))
-		  (setq g0 (` ((, g0) t)))))
-	    (if (charsetp g1)
-		(if (plist-get props 'force-g1-on-output)
-		    (setq g1 (` (nil (, g1))))
-		  (setq g1 (` ((, g1) t)))))
-	    (if (charsetp g2)
-		(if (plist-get props 'force-g2-on-output)
-		    (setq g2 (` (nil (, g2))))
-		  (setq g2 (` ((, g2) t)))))
-	    (if (charsetp g3)
-		(if (plist-get props 'force-g3-on-output)
-		    (setq g3 (` (nil (, g3))))
-		  (setq g3 (` ((, g3) t)))))
-	    (` ((, name) 2 (, mnemonic) (, doc-string)
-		((, g0) (, g1) (, g2) (, g3)
-		 (, (plist-get props 'short))
-		 (, (not (plist-get props 'no-ascii-eol)))
-		 (, (not (plist-get props 'no-ascii-cntl)))
-		 (, (plist-get props 'seven))
-		 t
-		 (, (not (plist-get props 'lock-shift)))
-		 (, use-roman)
-		 (, use-oldjis)
-		 (, (plist-get props 'no-iso6429))
-		 nil nil nil nil)
-		(, properties) (, eol-type)))))
-	 ((eq type 'big5)
-	  (` ((, name) 3 (, mnemonic) (, doc-string)
-	      nil (, properties) (, eol-type))))
-	 ((eq type 'ccl)
-	  (` ((, name) 4 (, mnemonic) (, doc-string)
-	      ((, (plist-get props 'decode)) . (, (plist-get props 'encode)))
-	      (, properties) (, eol-type))))
-	 (t
-	  (error "unsupported XEmacs style make-coding-style arguments: %S"
-		 (` ((, name) (, type) (, doc-string) (, props))))))))
-    (defadvice make-coding-system
-      (before ccl-compat (name type &rest ad-subr-args) activate)
-      "Emulate XEmacs style make-coding-system."
-      (when (and (symbolp type) (not (memq type '(t nil))))
-        (let ((args (apply 'transform-make-coding-system-args
-	                   name type ad-subr-args)))
-	  (setq type (cadr args)
-	        ad-subr-args (cddr args)))))))
+			      (let ((mnemonic (string-to-char (or (plist-get props 'mnemonic) "?")))
+				    (eol-type (plist-get props 'eol-type))
+				    properties tmp)
+				(cond
+				 ((eq eol-type 'lf) (setq eol-type 'unix))
+				 ((eq eol-type 'crlf) (setq eol-type 'dos))
+				 ((eq eol-type 'cr) (setq eol-type 'mac)))
+				(if (setq tmp (plist-get props 'post-read-conversion))
+				    (setq properties (plist-put properties 'post-read-conversion tmp)))
+				(if (setq tmp (plist-get props 'pre-write-conversion))
+				    (setq properties (plist-put properties 'pre-write-conversion tmp)))
+				(cond
+				 ((eq type 'shift-jis)
+				  `(,name 1 ,mnemonic ,doc-string
+					  nil ,properties ,eol-type))
+				 ((eq type 'iso2022) ; This is not perfect.
+				  (if (plist-get props 'escape-quoted)
+				      (error "escape-quoted is not supported: %S"
+					     `(,name ,type ,doc-string ,props)))
+				  (let ((g0 (plist-get props 'charset-g0))
+					(g1 (plist-get props 'charset-g1))
+					(g2 (plist-get props 'charset-g2))
+					(g3 (plist-get props 'charset-g3))
+					(use-roman
+					 (and
+					  (eq (cadr (assoc 'latin-jisx0201
+							   (plist-get props 'input-charset-conversion)))
+					      'ascii)
+					  (eq (cadr (assoc 'ascii
+							   (plist-get props 'output-charset-conversion)))
+					      'latin-jisx0201)))
+					(use-oldjis
+					 (and
+					  (eq (cadr (assoc 'japanese-jisx0208-1978
+							   (plist-get props 'input-charset-conversion)))
+					      'japanese-jisx0208)
+					  (eq (cadr (assoc 'japanese-jisx0208
+							   (plist-get props 'output-charset-conversion)))
+					      'japanese-jisx0208-1978))))
+				    (if (charsetp g0)
+					(if (plist-get props 'force-g0-on-output)
+					    (setq g0 `(nil ,g0))
+					  (setq g0 `(,g0 t))))
+				    (if (charsetp g1)
+					(if (plist-get props 'force-g1-on-output)
+					    (setq g1 `(nil ,g1))
+					  (setq g1 `(,g1 t))))
+				    (if (charsetp g2)
+					(if (plist-get props 'force-g2-on-output)
+					    (setq g2 `(nil ,g2))
+					  (setq g2 `(,g2 t))))
+				    (if (charsetp g3)
+					(if (plist-get props 'force-g3-on-output)
+					    (setq g3 `(nil ,g3))
+					  (setq g3 `(,g3 t))))
+				    `(,name 2 ,mnemonic ,doc-string
+					    (,g0 ,g1 ,g2 ,g3
+						 ,(plist-get props 'short)
+						 ,(not (plist-get props 'no-ascii-eol))
+						 ,(not (plist-get props 'no-ascii-cntl))
+						 ,(plist-get props 'seven)
+						 t
+						 ,(not (plist-get props 'lock-shift))
+						 ,use-roman
+						 ,use-oldjis
+						 ,(plist-get props 'no-iso6429)
+						 nil nil nil nil)
+					    ,properties ,eol-type)))
+				 ((eq type 'big5)
+				  `(,name 3 ,mnemonic ,doc-string
+					  nil ,properties ,eol-type))
+				 ((eq type 'ccl)
+				  `(,name 4 ,mnemonic ,doc-string
+					  (,(plist-get props 'decode) . ,(plist-get props 'encode))
+					  ,properties ,eol-type))
+				 (t
+				  (error "unsupported XEmacs style make-coding-style arguments: %S"
+					 `(,name ,type ,doc-string ,props))))))
+			    (defadvice make-coding-system
+			      (before ccl-compat (name type &rest ad-subr-args) activate)
+			      "Emulate XEmacs style make-coding-system."
+			      (when (and (symbolp type) (not (memq type '(t nil))))
+				(let ((args (apply 'transform-make-coding-system-args
+						   name type ad-subr-args)))
+				  (setq type (cadr args)
+					ad-subr-args (cddr args)))))))
 
 
 ;;; @ end
