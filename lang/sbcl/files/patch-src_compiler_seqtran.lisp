--- src/compiler/seqtran.lisp	2009/05/18 07:58:11	1.103
+++ src/compiler/seqtran.lisp	2009/06/04 18:01:32	1.104
@@ -569,40 +569,44 @@
                                         #!+#.(cl:if (cl:= 64 sb!vm:n-word-bits) '(and) '(or))
                                         (:complex-single-float
                                          (logior (ash (single-float-bits (imagpart tmp)) 32)
-                                                 (single-float-bits (realpart tmp)))))))
+                                                 (ldb (byte 32 0)
+                                                      (single-float-bits (realpart tmp))))))))
                                 (res bits))
                            (loop for i of-type sb!vm:word from n-bits by n-bits
                                  until (= i sb!vm:n-word-bits)
                                  do (setf res (ldb (byte sb!vm:n-word-bits 0)
                                                    (logior res (ash bits i)))))
                            res))
-                       `(let* ((bits (ldb (byte ,n-bits 0)
-                                          ,(ecase kind
-                                                  (:tagged
-                                                   `(ash item ,sb!vm:n-fixnum-tag-bits))
-                                                  (:char
-                                                   `(char-code item))
-                                                  (:bits
-                                                   `item)
-                                                  (:single-float
-                                                   `(single-float-bits item))
-                                                  #!+#.(cl:if (cl:= 64 sb!vm:n-word-bits) '(and) '(or))
-                                                  (:double-float
-                                                   `(logior (ash (double-float-high-bits item) 32)
-                                                            (double-float-low-bits item)))
-                                                  #!+#.(cl:if (cl:= 64 sb!vm:n-word-bits) '(and) '(or))
-                                                  (:complex-single-float
-                                                   `(logior (ash (single-float-bits (imagpart item)) 32)
-                                                            (single-float-bits (realpart item)))))))
-                               (res bits))
-                          (declare (type sb!vm:word res))
-                          ,@(unless (= sb!vm:n-word-bits n-bits)
-                                    `((loop for i of-type sb!vm:word from ,n-bits by ,n-bits
-                                            until (= i sb!vm:n-word-bits)
-                                            do (setf res
-                                                     (ldb (byte ,sb!vm:n-word-bits 0)
-                                                          (logior res (ash bits (truly-the (integer 0 ,(- sb!vm:n-word-bits n-bits)) i))))))))
-                          res))))
+                       (progn
+                         (delay-ir1-transform node :constraint)
+                        `(let* ((bits (ldb (byte ,n-bits 0)
+                                           ,(ecase kind
+                                                   (:tagged
+                                                    `(ash item ,sb!vm:n-fixnum-tag-bits))
+                                                   (:char
+                                                    `(char-code item))
+                                                   (:bits
+                                                    `item)
+                                                   (:single-float
+                                                    `(single-float-bits item))
+                                                   #!+#.(cl:if (cl:= 64 sb!vm:n-word-bits) '(and) '(or))
+                                                   (:double-float
+                                                    `(logior (ash (double-float-high-bits item) 32)
+                                                             (double-float-low-bits item)))
+                                                   #!+#.(cl:if (cl:= 64 sb!vm:n-word-bits) '(and) '(or))
+                                                   (:complex-single-float
+                                                    `(logior (ash (single-float-bits (imagpart item)) 32)
+                                                             (ldb (byte 32 0)
+                                                                  (single-float-bits (realpart item))))))))
+                                (res bits))
+                           (declare (type sb!vm:word res))
+                           ,@(unless (= sb!vm:n-word-bits n-bits)
+                                     `((loop for i of-type sb!vm:word from ,n-bits by ,n-bits
+                                             until (= i sb!vm:n-word-bits)
+                                             do (setf res
+                                                      (ldb (byte ,sb!vm:n-word-bits 0)
+                                                           (logior res (ash bits (truly-the (integer 0 ,(- sb!vm:n-word-bits n-bits)) i))))))))
+                           res)))))
              (values
               `(with-array-data ((data seq)
                                  (start start)
