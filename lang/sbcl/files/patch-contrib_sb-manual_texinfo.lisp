--- contrib/sb-manual/texinfo.lisp.orig	2026-07-28 08:09:25 UTC
+++ contrib/sb-manual/texinfo.lisp
@@ -1,5 +1,30 @@
 (in-package :sb-manual)
 
+(defun xref-defined-p (xref)
+  (let ((name (xref-name xref))
+        (locative-type (xref-locative-type xref)))
+    (case locative-type
+      ((function generic-function)
+       (ignore-errors (fdefinition name)))
+      ((variable)
+       (member (sb-int:info :variable :kind name)
+               '(:global :special :constant)))
+      ((declaration)
+       (find name (sb-cltl2:declaration-information 'declaration)))
+      ((class structure condition)
+       (find-class name nil))
+      ((type)
+       (sb-ext:defined-type-name-p name))
+      (t
+       (cond ((eq locative-type (dummy 'macro))
+              (ignore-errors (macro-function name)))
+             ((or (eq locative-type (dummy 'setf-function))
+                  (eq locative-type (dummy 'setf-generic-function)))
+              (ignore-errors (fdefinition name)))
+             (t
+              (assert nil () "Unexpected locative type in ~S."
+                      xref)))))))
+
 ;;; We don't DEFINE-DUMMY DREF:ARGLIST and DREF:DOCSTRING because we
 ;;; don't want USE-PAX to affect Texinfo output, which it would
 ;;; because DREF:ARGLIST differs from the {incom,re}prehensible
@@ -179,40 +204,42 @@
                           :depth (1+ depth))))))))))))
 
 (defun emit-texinfo-for-definition (xref)
-  (multiple-value-bind (docstring *package*) (%docstring xref)
-    (multiple-value-bind (type index)
-        (locative-type-to-texinfo (xref-locative-type xref))
-      (let* ((name (xref-name xref))
-             (*print-case* :downcase)
-             ;; For e.g. #'print
-             (*print-pretty* t)
-             ;; The arglist must be on the @deffn line.
-             (*print-right-margin* most-positive-fixnum))
-        (format t "@anchor{~A ~A ~A}~%" type
-                (string-downcase (package-name (symbol-package name)))
-                (string-downcase (symbol-name name)))
-        ;; E.g. @vvindex @sortas{save-hooks* sb-ext} *save-hooks* [sb-ext]
-        (let ((symbol-name (string-downcase (symbol-name name)))
-              (symbol-package-name
-                (string-downcase (package-name (symbol-package name)))))
-          (format t "@~A @sortas{~A ~A} ~A [~A]~%"
-                  index
-                  (sort-as-name symbol-name)
-                  (sort-as-name symbol-package-name)
-                  symbol-name
-                  symbol-package-name))
-        ;; Since we took indexing into our own hands, we just use
-        ;; @deffn for all definitions. We could also use @defblock and
-        ;; @defline.
-        (format t "@deffn{~A} ~A~{ ~A~}~%"
-                ;; E.g. "Variable"
-                type
-                (let ((*package* (find-package :cl)))
-                  (prin1-to-string name))
-                (%arglist xref))
-        (when docstring
-          (emit-texinfo-for-docstring docstring (%arglist xref)))
-        (format t "@end deffn~%")))))
+  (if (not (xref-defined-p xref))
+      (warn "~@<Not documenting ~S because it is not defined.~:@>" xref)
+      (multiple-value-bind (docstring *package*) (%docstring xref)
+        (multiple-value-bind (type index)
+            (locative-type-to-texinfo (xref-locative-type xref))
+          (let* ((name (xref-name xref))
+                 (*print-case* :downcase)
+                 ;; For e.g. #'print
+                 (*print-pretty* t)
+                 ;; The arglist must be on the @deffn line.
+                 (*print-right-margin* most-positive-fixnum))
+            (format t "@anchor{~A ~A ~A}~%" type
+                    (string-downcase (package-name (symbol-package name)))
+                    (string-downcase (symbol-name name)))
+            ;; E.g. @vvindex @sortas{save-hooks* sb-ext} *save-hooks* [sb-ext]
+            (let ((symbol-name (string-downcase (symbol-name name)))
+                  (symbol-package-name
+                    (string-downcase (package-name (symbol-package name)))))
+              (format t "@~A @sortas{~A ~A} ~A [~A]~%"
+                      index
+                      (sort-as-name symbol-name)
+                      (sort-as-name symbol-package-name)
+                      symbol-name
+                      symbol-package-name))
+            ;; Since we took indexing into our own hands, we just use
+            ;; @deffn for all definitions. We could also use @defblock and
+            ;; @defline.
+            (format t "@deffn{~A} ~A~{ ~A~}~%"
+                    ;; E.g. "Variable"
+                    type
+                    (let ((*package* (find-package :cl)))
+                      (prin1-to-string name))
+                    (%arglist xref))
+            (when docstring
+              (emit-texinfo-for-docstring docstring (%arglist xref)))
+            (format t "@end deffn~%"))))))
 
 ;;; Remove leading non-alphanumeric characters. They are not important
 ;;; when sorting names into indices.
