Index: pym.el
===================================================================
--- pym.el.orig	2005-07-06 02:08:53 UTC
+++ pym.el
@@ -63,15 +63,15 @@
 See also the function `defun'."
   (or (and (fboundp name)
 	   (not (get name 'defun-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (defun (, name) (,@ everything-else))
-	       ;; This `defun' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defun-maybe t))))))
+      `(or (fboundp (quote ,name))
+	   (prog1
+	       (defun ,name ,@everything-else)
+	     ;; This `defun' will be compiled to `fset',
+	     ;; which does not update `load-history'.
+	     ;; We must update `current-load-list' explicitly.
+	     (setq current-load-list
+		   (cons (quote ,name) current-load-list))
+	     (put (quote ,name) 'defun-maybe t)))))
 
 (put 'defmacro-maybe 'lisp-indent-function 'defun)
 (defmacro defmacro-maybe (name &rest everything-else)
@@ -79,15 +79,15 @@ See also the function `defun'."
 See also the function `defmacro'."
   (or (and (fboundp name)
 	   (not (get name 'defmacro-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (defmacro (, name) (,@ everything-else))
-	       ;; This `defmacro' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defmacro-maybe t))))))
+      `(or (fboundp (quote ,name))
+	   (prog1
+	       (defmacro ,name ,@everything-else)
+	     ;; This `defmacro' will be compiled to `fset',
+	     ;; which does not update `load-history'.
+	     ;; We must update `current-load-list' explicitly.
+	     (setq current-load-list
+		   (cons (quote ,name) current-load-list))
+	     (put (quote ,name) 'defmacro-maybe t)))))
 
 (put 'defsubst-maybe 'lisp-indent-function 'defun)
 (defmacro defsubst-maybe (name &rest everything-else)
@@ -95,15 +95,15 @@ See also the function `defmacro'."
 See also the macro `defsubst'."
   (or (and (fboundp name)
 	   (not (get name 'defsubst-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (defsubst (, name) (,@ everything-else))
-	       ;; This `defsubst' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defsubst-maybe t))))))
+      `(or (fboundp (quote ,name))
+	   (prog1
+	       (defsubst ,name ,@everything-else)
+	     ;; This `defsubst' will be compiled to `fset',
+	     ;; which does not update `load-history'.
+	     ;; We must update `current-load-list' explicitly.
+	     (setq current-load-list
+		   (cons (quote ,name) current-load-list))
+	     (put (quote ,name) 'defsubst-maybe t)))))
 
 (defmacro defalias-maybe (symbol definition)
   "Define SYMBOL as an alias for DEFINITION if SYMBOL is not defined.
@@ -111,35 +111,35 @@ See also the function `defalias'."
   (setq symbol (eval symbol))
   (or (and (fboundp symbol)
 	   (not (get symbol 'defalias-maybe)))
-      (` (or (fboundp (quote (, symbol)))
-	     (prog1
-		 (defalias (quote (, symbol)) (, definition))
-	       ;; `defalias' updates `load-history' internally.
-	       (put (quote (, symbol)) 'defalias-maybe t))))))
+      `(or (fboundp (quote ,symbol))
+	   (prog1
+	       (defalias (quote ,symbol) ,definition)
+	     ;; `defalias' updates `load-history' internally.
+	     (put (quote ,symbol) 'defalias-maybe t)))))
 
 (defmacro defvar-maybe (name &rest everything-else)
   "Define NAME as a variable if NAME is not defined.
 See also the function `defvar'."
   (or (and (boundp name)
 	   (not (get name 'defvar-maybe)))
-      (` (or (boundp (quote (, name)))
-	     (prog1
-		 (defvar (, name) (,@ everything-else))
-	       ;; byte-compiler will generate code to update
-	       ;; `load-history'.
-	       (put (quote (, name)) 'defvar-maybe t))))))
+      `(or (boundp (quote ,name))
+	   (prog1
+	       (defvar ,name ,@everything-else)
+	     ;; byte-compiler will generate code to update
+	     ;; `load-history'.
+	     (put (quote ,name) 'defvar-maybe t)))))
 
 (defmacro defconst-maybe (name &rest everything-else)
   "Define NAME as a constant variable if NAME is not defined.
 See also the function `defconst'."
   (or (and (boundp name)
 	   (not (get name 'defconst-maybe)))
-      (` (or (boundp (quote (, name)))
-	     (prog1
-		 (defconst (, name) (,@ everything-else))
-	       ;; byte-compiler will generate code to update
-	       ;; `load-history'.
-	       (put (quote (, name)) 'defconst-maybe t))))))
+      `(or (boundp (quote ,name))
+	   (prog1
+	       (defconst ,name ,@everything-else)
+	     ;; byte-compiler will generate code to update
+	     ;; `load-history'.
+	     (put (quote ,name) 'defconst-maybe t)))))
 
 (defmacro defun-maybe-cond (name args &optional doc &rest clauses)
   "Define NAME as a function if NAME is not defined.
@@ -152,26 +152,26 @@ See also the function `defun'."
 	    doc nil))
   (or (and (fboundp name)
 	   (not (get name 'defun-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (static-cond
-		  (,@ (mapcar
-		       (function
-			(lambda (case)
-			  (list (car case)
-				(if doc
-				    (` (defun (, name) (, args)
-					 (, doc)
-					 (,@ (cdr case))))
-				  (` (defun (, name) (, args)
-				       (,@ (cdr case))))))))
-		       clauses)))
-	       ;; This `defun' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defun-maybe t))))))
+      `(or (fboundp (quote ,name))
+	   (prog1
+	       (static-cond
+		,@(mapcar
+		   (function
+		    (lambda (case)
+		      (list (car case)
+			    (if doc
+				`(defun ,name ,args
+				   ,doc
+				   ,@(cdr case))
+			      `(defun ,name ,args
+				 ,@ (cdr case))))))
+		   clauses))
+	     ;; This `defun' will be compiled to `fset',
+	     ;; which does not update `load-history'.
+	     ;; We must update `current-load-list' explicitly.
+	     (setq current-load-list
+		   (cons (quote ,name) current-load-list))
+	     (put (quote ,name) 'defun-maybe t)))))
 
 (defmacro defmacro-maybe-cond (name args &optional doc &rest clauses)
   "Define NAME as a macro if NAME is not defined.
@@ -184,26 +184,26 @@ See also the function `defmacro'."
 	    doc nil))
   (or (and (fboundp name)
 	   (not (get name 'defmacro-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (static-cond
-		  (,@ (mapcar
-		       (function
-			(lambda (case)
-			  (list (car case)
-				(if doc
-				    (` (defmacro (, name) (, args)
-					 (, doc)
-					 (,@ (cdr case))))
-				  (` (defmacro (, name) (, args)
-				       (,@ (cdr case))))))))
-		       clauses)))
-	       ;; This `defmacro' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defmacro-maybe t))))))
+      `(or (fboundp (quote ,name))
+	   (prog1
+	       (static-cond
+		,@(mapcar
+		   (function
+		    (lambda (case)
+		      (list (car case)
+			    (if doc
+				`(defmacro ,name ,args
+				   ,doc
+				   ,@(cdr case))
+			      `(defmacro ,name ,args
+				 @(cdr case))))))
+		   clauses))
+	     ;; This `defmacro' will be compiled to `fset',
+	     ;; which does not update `load-history'.
+	     ;; We must update `current-load-list' explicitly.
+	     (setq current-load-list
+		   (cons (quote ,name) current-load-list))
+	     (put (quote ,name) 'defmacro-maybe t)))))
 
 (defmacro defsubst-maybe-cond (name args &optional doc &rest clauses)
   "Define NAME as an inline function if NAME is not defined.
@@ -216,26 +216,26 @@ See also the macro `defsubst'."
 	    doc nil))
   (or (and (fboundp name)
 	   (not (get name 'defsubst-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (static-cond
-		  (,@ (mapcar
-		       (function
-			(lambda (case)
-			  (list (car case)
-				(if doc
-				    (` (defsubst (, name) (, args)
-					 (, doc)
-					 (,@ (cdr case))))
-				  (` (defsubst (, name) (, args)
-				       (,@ (cdr case))))))))
-		       clauses)))
-	       ;; This `defsubst' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defsubst-maybe t))))))
+      `(or (fboundp (quote ,name))
+	   (prog1
+	       (static-cond
+		,@ (mapcar
+		    (function
+		     (lambda (case)
+		       (list (car case)
+			     (if doc
+				 `(defsubst ,name ,args
+				    ,doc
+				    ,@ (cdr case))
+			       `(defsubst ,name ,args
+				  ,@(cdr case))))))
+		    clauses))
+	     ;; This `defsubst' will be compiled to `fset',
+	     ;; which does not update `load-history'.
+	     ;; We must update `current-load-list' explicitly.
+	     (setq current-load-list
+		   (cons (quote ,name) current-load-list))
+	     (put (quote ,name) 'defsubst-maybe t)))))
 
 
 ;;; Edebug spec.
@@ -246,7 +246,7 @@ See also the macro `defsubst'."
   "Set the edebug-form-spec property of SYMBOL according to SPEC.
 Both SYMBOL and SPEC are unevaluated. The SPEC can be 0, t, a symbol
 \(naming a function\), or a list."
-  (` (put (quote (, symbol)) 'edebug-form-spec (quote (, spec)))))
+  `(put (quote ,symbol) 'edebug-form-spec (quote ,spec)))
 
 ;; edebug-spec for `def*-maybe' macros.
 (def-edebug-spec defun-maybe defun)
