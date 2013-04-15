--- its.el.orig	2002-08-02 12:07:34.000000000 +0900
+++ its.el	2013-03-30 17:11:53.000000000 +0900
@@ -397,7 +397,7 @@
 (defun its-self-insert-char ()
   (interactive)
   (let ((inhibit-read-only t)
-	(key last-command-char)
+	(key last-command-event)
 	(cursor (get-text-property (point) 'its-cursor))
 	(syl (get-text-property (1- (point)) 'its-syl)))
     (cond
@@ -1264,7 +1264,7 @@
   (interactive "P")
   (let ((syl (and (null (get-text-property (point) 'its-cursor))
 		  (get-text-property (1- (point)) 'its-syl))))
-    (if (its-keyseq-acceptable-p (vector last-command-char) syl)
+    (if (its-keyseq-acceptable-p (vector last-command-event) syl)
 	(its-self-insert-char)
       (its-kick-convert-region n))))

