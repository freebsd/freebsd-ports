--- md4.el.orig	2007-09-06 08:39:48.000000000 +0900
+++ md4.el	2012-08-23 00:42:35.000000000 +0900
@@ -88,11 +88,10 @@
 (defsubst md4-H (x y z) (logxor x y z))
 
 (defmacro md4-make-step (name func)
-  (`
-   (defun (, name) (a b c d xk s ac)
+  `(defun ,name (a b c d xk s ac)
      (let*
-         ((h1 (+ (car a) ((, func) (car b) (car c) (car d)) (car xk) (car ac)))
-          (l1 (+ (cdr a) ((, func) (cdr b) (cdr c) (cdr d)) (cdr xk) (cdr ac)))
+         ((h1 (+ (car a) (,func (car b) (car c) (car d)) (car xk) (car ac)))
+          (l1 (+ (cdr a) (,func (cdr b) (cdr c) (cdr d)) (cdr xk) (cdr ac)))
           (h2 (logand 65535 (+ h1 (lsh l1 -16))))
           (l2 (logand 65535 l1))
 	  ;; cyclic shift of 32 bits integer
@@ -102,7 +101,7 @@
           (l3 (logand 65535 (if (> s 15)
                                 (+ (lsh l2 (- s 32)) (lsh h2 (- s 16)))
                               (+ (lsh l2 s) (lsh h2 (- s 16)))))))
-       (cons h3 l3)))))
+       (cons h3 l3))))
 
 (md4-make-step md4-round1 md4-F)
 (md4-make-step md4-round2 md4-G)
