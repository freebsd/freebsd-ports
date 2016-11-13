Index: product.el
===================================================================
--- product.el.orig	2006-04-24 05:53:58 UTC
+++ product.el
@@ -232,21 +232,21 @@ PRODUCT-DEF is a definition of the produ
 	 (product-version (product-version product))
 	 (product-code-name (product-code-name product))
 	 (product-version-string (product-version-string product)))
-    (` (progn
-	 (, product-def)
-	 (put (, feature) 'product
-	      (let ((product (product-find-by-name (, product-name))))
-		(product-run-checkers product '(, product-version))
-		(and (, product-family)
-		     (product-add-to-family (, product-family)
-					    (, product-name)))
-		(product-add-feature product (, feature))
-		(if (equal '(, product-version) (product-version product))
-		    product
-		  (vector (, product-name) (, product-family)
-			  '(, product-version) (, product-code-name)
-			  nil nil nil (, product-version-string)))))
-	 (, feature-def)))))
+    `(progn
+       ,product-def
+       (put ,feature 'product
+	    (let ((product (product-find-by-name ,product-name)))
+	      (product-run-checkers product ',product-version)
+	      (and ,product-family
+		   (product-add-to-family ,product-family
+					  ,product-name))
+	      (product-add-feature product ,feature)
+	      (if (equal ',product-version (product-version product))
+		  product
+		(vector ,product-name ,product-family
+			',product-version ,product-code-name
+			nil nil nil ,product-version-string))))
+       ,feature-def)))
 
 (defun product-version-as-string (product)
   "Return version number of product as a string.
@@ -293,13 +293,13 @@ The 1st argument is a product structure.
 PRODUCT is a product structure which returned by `product-define'."
   (let (dest)
     (product-for-each product nil
-     (function
-      (lambda (product)
-	(let ((str (product-string-1 product nil)))
-	  (if str
-	      (setq dest (if dest
-			     (concat dest " " str)
-			   str)))))))
+		      (function
+		       (lambda (product)
+			 (let ((str (product-string-1 product nil)))
+			   (if str
+			       (setq dest (if dest
+					      (concat dest " " str)
+					    str)))))))
     dest))
 
 (defun product-string-verbose (product)
@@ -307,13 +307,13 @@ PRODUCT is a product structure which ret
 PRODUCT is a product structure which returned by `product-define'."
   (let (dest)
     (product-for-each product nil
-     (function
-      (lambda (product)
-	(let ((str (product-string-1 product t)))
-	  (if str
-	      (setq dest (if dest
-			     (concat dest " " str)
-			   str)))))))
+		      (function
+		       (lambda (product)
+			 (let ((str (product-string-1 product t)))
+			   (if str
+			       (setq dest (if dest
+					      (concat dest " " str)
+					    str)))))))
     dest))
 
 (defun product-version-compare (v1 v2)
