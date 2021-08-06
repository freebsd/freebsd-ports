--- work/sbcl-2.1.7/tests/seq.pure.lisp	2021-07-30 10:42:10.000000000 +0200
+++ /home/krion/sbcl/tests/seq.pure.lisp	2021-08-06 22:34:09.303934000 +0200
@@ -584,3 +584,18 @@
         ;; Try all other numeric array types
         (dolist (y arrays)
           (assert (equalp x y)))))))
+
+;; lp#1938598
+(with-test (:name :vector-replace-self)
+  ;; example 1
+  (let ((string (make-array 0 :adjustable t :fill-pointer 0 :element-type 'character)))
+    (declare (notinline replace))
+    (vector-push-extend #\_ string)
+    ;; also test it indirectly
+    (replace string string :start1 1 :start2 0))
+  ;; example 2
+  (let ((string (make-array 0 :adjustable t :fill-pointer 0 :element-type 'character)))
+    (declare (notinline replace))
+    (loop for char across "tset" do (vector-push-extend char string))
+    (replace string string :start2 1 :start1 2)
+    (assert (string= string "tsse"))))
