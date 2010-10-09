--- yc.el.orig	2010-09-30 13:22:22.000000000 +0900
+++ yc.el	2010-09-30 13:26:09.000000000 +0900
@@ -1736,6 +1736,7 @@
 				   (error nil))))
 	    (yc-eval-sexp (car expr)))))
       (setq files (cdr files)))
+    (message "")
     (if romkana-table
 	(setq yc-rH-conv-dic (yc-search-file-first-in-path
 			      romkana-table (list "." (getenv "HOME")
