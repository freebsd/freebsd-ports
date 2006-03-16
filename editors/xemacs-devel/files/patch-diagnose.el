Index: lisp/diagnose.el
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/lisp/diagnose.el,v
retrieving revision 1.7
retrieving revision 1.8
diff -u -r1.7 -r1.8
--- lisp/diagnose.el	2005/11/25 01:41:46	1.7
+++ lisp/diagnose.el	2006/03/12 09:10:39	1.8
@@ -142,7 +142,7 @@
 	    (princ "\n")
 	    (map-plist #'(lambda (stat num)
 			   (when (string-match 
-				  "\\(.*\\)-storage\\$"
+				  "\\(.*\\)-storage$"
 				  (symbol-name stat))
 			     (incf total num)
 			     (princ (format fmt
