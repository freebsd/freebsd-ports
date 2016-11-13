--- md5-el.el.orig	2000-11-06 13:03:19 UTC
+++ md5-el.el
@@ -169,11 +169,10 @@ Returns a vector of 16 bytes containing 
 (defsubst md5-I (x y z) (logxor y (logior x (logand 65535 (lognot z)))))
 
 (defmacro md5-make-step (name func)
-  (`
-   (defun (, name) (a b c d x s ac)
+  `(defun ,name (a b c d x s ac)
      (let*
-         ((m1 (+ (car a) ((, func) (car b) (car c) (car d)) (car x) (car ac)))
-          (l1 (+ (cdr a) ((, func) (cdr b) (cdr c) (cdr d)) (cdr x) (cdr ac)))
+         ((m1 (+ (car a) (,func (car b) (car c) (car d)) (car x) (car ac)))
+          (l1 (+ (cdr a) (,func (cdr b) (cdr c) (cdr d)) (cdr x) (cdr ac)))
           (m2 (logand 65535 (+ m1 (lsh l1 -16))))
           (l2 (logand 65535 l1))
           (m3 (logand 65535 (if (> s 15)
@@ -182,7 +181,7 @@ Returns a vector of 16 bytes containing 
           (l3 (logand 65535 (if (> s 15)
                                 (+ (lsh l2 (- s 32)) (lsh m2 (- s 16)))
                               (+ (lsh l2 s) (lsh m2 (- s 16)))))))
-       (md5-add (cons m3 l3) b)))))
+       (md5-add (cons m3 l3) b))))
 
 (md5-make-step md5-FF md5-F)
 (md5-make-step md5-GG md5-G)
