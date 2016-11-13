Index: md4.el
===================================================================
--- md4.el.orig	2007-09-05 23:39:48 UTC
+++ md4.el
@@ -78,21 +78,20 @@ bytes long.  N is required to handle str
       (setq m (md4-copy64 (substring buf 64)))
       (md4-64 m)))
 
-    (concat (md4-pack-int32 (aref md4-buffer 0))
-	    (md4-pack-int32 (aref md4-buffer 1))
-	    (md4-pack-int32 (aref md4-buffer 2))
-	    (md4-pack-int32 (aref md4-buffer 3))))
+  (concat (md4-pack-int32 (aref md4-buffer 0))
+	  (md4-pack-int32 (aref md4-buffer 1))
+	  (md4-pack-int32 (aref md4-buffer 2))
+	  (md4-pack-int32 (aref md4-buffer 3))))
 
 (defsubst md4-F (x y z) (logior (logand x y) (logand (lognot x) z)))
 (defsubst md4-G (x y z) (logior (logand x y) (logand x z) (logand y z)))
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
@@ -102,7 +101,7 @@ bytes long.  N is required to handle str
           (l3 (logand 65535 (if (> s 15)
                                 (+ (lsh l2 (- s 32)) (lsh h2 (- s 16)))
                               (+ (lsh l2 s) (lsh h2 (- s 16)))))))
-       (cons h3 l3)))))
+       (cons h3 l3))))
 
 (md4-make-step md4-round1 md4-F)
 (md4-make-step md4-round2 md4-G)
