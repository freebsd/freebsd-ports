--- psgml-lucid.el.orig	2015-11-12 06:36:57 UTC
+++ psgml-lucid.el
@@ -126,16 +126,16 @@ if the item is selected."
 		(loop for c in type collect
 		      (if (atom c)
 			  (vector (prin1-to-string c)
-				  (`(setq (, var) (, c)))
+				  `(setq ,var ,c)
 				  :style 'toggle
-				  :selected (`(eq (, var) '(, c))))
+				  :selected `(eq ,var ',c))
 			(vector (car c)
-				(`(setq (, var) '(,(cdr c))))
+				`(setq ,var ',(cdr c))
 				:style 'toggle
-				:selected (`(eq (, var) '(,(cdr c)))))))))
+				:selected `(eq ,var ',(cdr c)))))))
 	 (t
 	  (vector desc
-		  (`(sgml-do-set-option '(, var)))
+		  `(sgml-do-set-option ',var)
 		  t)))))
 
 
