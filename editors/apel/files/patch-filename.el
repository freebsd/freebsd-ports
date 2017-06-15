Index: filename.el
===================================================================
--- filename.el.orig	2005-07-06 02:08:52 UTC
+++ filename.el
@@ -102,26 +102,26 @@ Moreover, if you want to convert Japanes
 		inc-i '(1+ i))
 	(setq sref 'aref
 	      inc-i '(+ i (char-length chr))))
-      (` (let ((len (length (, string)))
-	       (b 0)(i 0)
-	       (dest ""))
-	   (while (< i len)
-	     (let ((chr ((, sref) (, string) i))
-		   (lst filename-replacement-alist)
-		   ret)
-	       (while (and lst (not ret))
-		 (if (if (functionp (car (car lst)))
-			 (setq ret (funcall (car (car lst)) chr))
-		       (setq ret (memq chr (car (car lst)))))
-		     t			; quit this loop.
-		   (setq lst (cdr lst))))
-	       (if ret
-		   (setq dest (concat dest (substring (, string) b i)
-				      (cdr (car lst)))
-			 i (, inc-i)
-			 b i)
-		 (setq i (, inc-i)))))
-	   (concat dest (substring (, string) b)))))))
+      `(let ((len (length ,string))
+	     (b 0)(i 0)
+	     (dest ""))
+	 (while (< i len)
+	   (let ((chr (,sref ,string i))
+		 (lst filename-replacement-alist)
+		 ret)
+	     (while (and lst (not ret))
+	       (if (if (functionp (car (car lst)))
+		       (setq ret (funcall (car (car lst)) chr))
+		     (setq ret (memq chr (car (car lst)))))
+		   t			; quit this loop.
+		 (setq lst (cdr lst))))
+	     (if ret
+		 (setq dest (concat dest (substring ,string b i)
+				    (cdr (car lst)))
+		       i ,inc-i
+		       b i)
+	       (setq i ,inc-i))))
+	 (concat dest (substring ,string b))))))
 
 (defun filename-special-filter (string)
   (filename-special-filter-1 string))
