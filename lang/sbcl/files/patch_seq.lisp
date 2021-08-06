--- work/sbcl-2.1.7/src/code/seq.lisp	2021-07-30 10:42:09.000000000 +0200
+++ /home/krion/sbcl/src/code/seq.lisp	2021-08-06 22:34:09.026438000 +0200
@@ -722,52 +722,53 @@
             collect `(eq ,tag ,(sb-vm:saetp-typecode saetp)))))
 
 ;;;; REPLACE
-(defun vector-replace (vector1 vector2 start1 start2 end1 diff)
-  (declare ((or (eql -1) index) start1 start2 end1)
-           (optimize (sb-c::insert-array-bounds-checks 0))
-           ((integer -1 1) diff))
-  (let ((tag1 (%other-pointer-widetag vector1))
-        (tag2 (%other-pointer-widetag vector2)))
-    (macrolet ((copy (&body body)
-                 `(do ((index1 start1 (+ index1 diff))
-                       (index2 start2 (+ index2 diff)))
-                      ((= index1 end1))
-                    (declare (fixnum index1 index2))
-                    ,@body)))
-      (when (= tag1 tag2)
-        (when (= tag1 sb-vm:simple-vector-widetag)
-          (copy (setf (svref vector1 index1) (svref vector2 index2)))
-          (return-from vector-replace vector1))
-        (let ((copier (sb-vm::blt-copier-for-widetag tag1)))
-          (when (functionp copier)
-            ;; VECTOR1 = destination, VECTOR2 = source, but copier wants FROM, TO
-            (funcall copier vector2 start2 vector1 start1 (- end1 start1))
-            (return-from vector-replace vector1))))
-      (let ((getter (the function (svref %%data-vector-reffers%% tag2)))
-            (setter (the function (svref %%data-vector-setters%% tag1))))
-        (copy (funcall setter vector1 index1 (funcall getter vector2 index2))))))
-  vector1)
 
 ;;; If we are copying around in the same vector, be careful not to copy the
 ;;; same elements over repeatedly. We do this by copying backwards.
+;;; Bounding indices were checked for validity by DEFINE-SEQUENCE-TRAVERSER.
 (defmacro vector-replace-from-vector ()
-  `(let ((nelts (min (- target-end target-start)
-                     (- source-end source-start))))
-     (with-array-data ((data1 target-sequence) (start1 target-start) (end1))
-       (declare (ignore end1))
-       (let ((end1 (the fixnum (+ start1 nelts))))
-         (if (and (eq target-sequence source-sequence)
-                  (> target-start source-start))
-             (let ((end (the fixnum (1- end1))))
-               (vector-replace data1 data1
-                               end
-                               (the fixnum (- end
-                                              (- target-start source-start)))
-                               (1- start1)
-                               -1))
-             (with-array-data ((data2 source-sequence) (start2 source-start) (end2))
-               (declare (ignore end2))
-               (vector-replace data1 data2 start1 start2 end1 1)))))
+  `(locally
+     (declare (optimize (safety 0)))
+     (let ((nelts (min (- target-end target-start)
+                       (- source-end source-start))))
+       (when (plusp nelts)
+       (with-array-data ((data1 target-sequence) (start1 target-start) (end1))
+         (progn end1)
+         (with-array-data ((data2 source-sequence) (start2 source-start) (end2))
+           (progn end2)
+           (let ((tag1 (%other-pointer-widetag data1))
+                 (tag2 (%other-pointer-widetag data2)))
+             (block replace
+               (when (= tag1 tag2)
+                 (when (= tag1 sb-vm:simple-vector-widetag) ; rely on the transform
+                   (replace (truly-the simple-vector data1)
+                            (truly-the simple-vector data2)
+                            :start1 start1 :end1 (truly-the index (+ start1 nelts))
+                            :start2 start2 :end2 (truly-the index (+ start2 nelts)))
+                   (return-from replace))
+                 (let ((copier (sb-vm::blt-copier-for-widetag tag1)))
+                   (when (functionp copier)
+                     ;; these copiers figure out which direction to step.
+                     ;; arg order is FROM, TO which is the opposite of REPLACE.
+                     (funcall copier data2 start2 data1 start1 nelts)
+                     (return-from replace))))
+               ;; General case is just like the code emitted by TRANSFORM-REPLACE
+               ;; but using the getter and setter.
+               (let ((getter (the function (svref %%data-vector-reffers%% tag2)))
+                     (setter (the function (svref %%data-vector-setters%% tag1))))
+                 (cond ((and (eq data1 data2) (> start1 start2))
+                        (do ((i (the (or (eql -1) index) (+ start1 nelts -1)) (1- i))
+                             (j (the (or (eql -1) index) (+ start2 nelts -1)) (1- j)))
+                            ((< i start1))
+                          (declare (index i j))
+                          (funcall setter data1 i (funcall getter data2 j))))
+                       (t
+                        (do ((i start1 (1+ i))
+                             (j start2 (1+ j))
+                             (end (the index (+ start1 nelts))))
+                            ((>= i end))
+                          (declare (index i j))
+                          (funcall setter data1 i (funcall getter data2 j))))))))))))
      target-sequence))
 
 (defmacro list-replace-from-list ()
@@ -819,44 +820,6 @@
         target-sequence)
      (declare (fixnum target-index source-index))
      (setf (aref target-sequence target-index) (car source-sequence))))
-
-;;;; The support routines for REPLACE are used by compiler transforms, so we
-;;;; worry about dealing with END being supplied or defaulting to NIL
-;;;; at this level.
-
-(defun list-replace-from-list* (target-sequence source-sequence target-start
-                                target-end source-start source-end)
-  (when (null target-end) (setq target-end (length target-sequence)))
-  (when (null source-end) (setq source-end (length source-sequence)))
-  (list-replace-from-list))
-
-(defun list-replace-from-vector* (target-sequence source-sequence target-start
-                                  target-end source-start source-end)
-  (when (null target-end) (setq target-end (length target-sequence)))
-  (when (null source-end) (setq source-end (length source-sequence)))
-  (list-replace-from-vector))
-
-(defun vector-replace-from-list* (target-sequence source-sequence target-start
-                                  target-end source-start source-end)
-  (when (null target-end) (setq target-end (length target-sequence)))
-  (when (null source-end) (setq source-end (length source-sequence)))
-  (vector-replace-from-list))
-
-(defun vector-replace-from-vector* (target-sequence source-sequence
-                                    target-start target-end source-start
-                                    source-end)
-  (when (null target-end) (setq target-end (length target-sequence)))
-  (when (null source-end) (setq source-end (length source-sequence)))
-  (vector-replace-from-vector))
-
-#+sb-unicode
-(defun simple-character-string-replace-from-simple-character-string*
-    (target-sequence source-sequence
-     target-start target-end source-start source-end)
-  (declare (type (simple-array character (*)) target-sequence source-sequence))
-  (when (null target-end) (setq target-end (length target-sequence)))
-  (when (null source-end) (setq source-end (length source-sequence)))
-  (vector-replace-from-vector))
 
 (define-sequence-traverser replace
     (target-sequence1 source-sequence2 &rest args &key start1 end1 start2 end2)
