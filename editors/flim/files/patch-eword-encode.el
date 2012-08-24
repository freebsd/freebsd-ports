--- eword-encode.el.orig	2007-09-06 16:48:50.000000000 +0900
+++ eword-encode.el	2012-08-23 00:42:35.000000000 +0900
@@ -162,15 +162,15 @@
 ;;;
 
 (defmacro make-ew-rword (text charset encoding type)
-  (` (list (, text)(, charset)(, encoding)(, type))))
+  `(list ,text ,charset ,encoding ,type))
 (defmacro ew-rword-text (rword)
-  (` (car (, rword))))
+  `(car ,rword))
 (defmacro ew-rword-charset (rword)
-  (` (car (cdr (, rword)))))
+  `(car (cdr ,rword)))
 (defmacro ew-rword-encoding (rword)
-  (` (car (cdr (cdr (, rword))))))
+  `(car (cdr (cdr ,rword))))
 (defmacro ew-rword-type (rword)
-  (` (car (cdr (cdr (cdr (, rword)))))))
+  `(car (cdr (cdr (cdr ,rword)))))
 
 (defun ew-find-charset-rule (charsets)
   (if charsets
