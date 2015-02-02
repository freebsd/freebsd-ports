--- egg/anthyipc.el.orig	2015-01-31 19:24:09.000000000 +0900
+++ egg/anthyipc.el	2015-02-02 00:32:22.000000000 +0900
@@ -46,8 +46,7 @@
 	  ,@vlist)
      (if (and (eq (process-status proc) 'run)
 	      (buffer-live-p buffer))
-	 (save-excursion
-	   (set-buffer buffer)
+	 (with-current-buffer buffer
 	   (erase-buffer)
 	   ,send-expr
 	   (goto-char (point-max))
