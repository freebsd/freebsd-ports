--- egg/cannarpc.el.orig	2015-01-31 19:23:34.000000000 +0900
+++ egg/cannarpc.el	2015-02-02 00:32:59.000000000 +0900
@@ -79,8 +79,7 @@
     (list
      'let v
      (append
-	`(save-excursion
-	   (set-buffer (process-buffer proc))
+	`(with-current-buffer (process-buffer proc)
 	   (erase-buffer)
 	   ,send-expr
 	   (process-send-region proc (point-min) (point-max))
