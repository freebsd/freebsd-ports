Index: static.el
===================================================================
--- static.el.orig	2005-07-06 02:08:53 UTC
+++ static.el
@@ -29,38 +29,38 @@
   "Like `if', but evaluate COND at compile time."
   (if (eval cond)
       then
-    (` (progn  (,@ else)))))
+    `(progn  ,@else)))
 
 (put 'static-when 'lisp-indent-function 1)
 (defmacro static-when (cond &rest body)
   "Like `when', but evaluate COND at compile time."
   (if (eval cond)
-      (` (progn (,@ body)))))
+      `(progn ,@body)))
 
 (put 'static-unless 'lisp-indent-function 1)
 (defmacro static-unless (cond &rest body)
   "Like `unless', but evaluate COND at compile time."
   (if (eval cond)
       nil
-    (` (progn (,@ body)))))
+    `(progn ,@body)))
 
 (put 'static-condition-case 'lisp-indent-function 2)
 (defmacro static-condition-case (var bodyform &rest handlers)
   "Like `condition-case', but evaluate BODYFORM at compile time."
-  (eval (` (condition-case (, var)
-	       (list (quote quote) (, bodyform))
-	     (,@ (mapcar
-		  (if var
-		      (function
-		       (lambda (h)
-			 (` ((, (car h))
-			     (list (quote funcall)
-				   (function (lambda ((, var)) (,@ (cdr h))))
-				   (list (quote quote) (, var)))))))
-		    (function
-		     (lambda (h)
-		       (` ((, (car h)) (quote (progn (,@ (cdr h)))))))))
-		  handlers))))))
+  (eval `(condition-case ,var
+	     (list (quote quote) ,bodyform)
+	   ,@(mapcar
+	      (if var
+		  (function
+		   (lambda (h)
+		     `(,(car h)
+		       (list (quote funcall)
+			     (function (lambda (,var) ,@(cdr h)))
+			     (list (quote quote) ,var)))))
+		(function
+		 (lambda (h)
+		   `(,(car h) (quote (progn ,@(cdr h)))))))
+	      handlers))))
 
 (put 'static-defconst 'lisp-indent-function 'defun)
 (defmacro static-defconst (symbol initvalue &optional docstring)
@@ -68,8 +68,8 @@
 
 The variable SYMBOL can be referred at both compile time and run time."
   (let ((value (eval initvalue)))
-    (eval (` (defconst (, symbol) (quote (, value)) (, docstring))))
-    (` (defconst (, symbol) (quote (, value)) (, docstring)))))
+    (eval `(defconst ,symbol (quote ,value) ,docstring))
+    `(defconst ,symbol (quote ,value) ,docstring)))
 
 (defmacro static-cond (&rest clauses)
   "Like `cond', but evaluate CONDITION part of each clause at compile time."
