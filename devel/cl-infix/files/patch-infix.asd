
$FreeBSD$

--- infix.asd.orig
+++ infix.asd
@@ -16,4 +16,4 @@
 	       (:static-file "COPYING")))
 
 (defmethod source-file-type ((f cl-source-file) (s (eql (find-system 'infix))))
-  "cl")
+  "lisp")
