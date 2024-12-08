--- src/compiler/ir1util.lisp.orig	2024-11-30 10:23:33 UTC
+++ src/compiler/ir1util.lisp
@@ -308,6 +308,9 @@
 (defun erase-lvar-type (lvar)
   (when lvar
     (setf (lvar-%derived-type lvar) nil)
+    (loop for annotation in (lvar-annotations lvar)
+          when (lvar-type-annotation-p annotation)
+          do (setf (lvar-annotation-fired annotation) t))
     (let ((dest (lvar-dest lvar)))
       (cond ((cast-p dest)
              (derive-node-type dest *wild-type* :from-scratch t)
