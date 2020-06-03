--- src/lsp/format.lsp.orig	2016-12-19 10:25:00 UTC
+++ src/lsp/format.lsp
@@ -308,11 +308,14 @@
                   :start (format-directive-start struct)
                   :end (format-directive-end struct))))
 
+;; Patch borrowed from SageMath
+(defconstant +format-directive-limit+ (1+ (char-code #\~)))
+
 #+formatter
 (defparameter *format-directive-expanders*
-  (make-array char-code-limit :initial-element nil))
+  (make-array +format-directive-limit+ :initial-element nil))
 (defparameter *format-directive-interpreters*
-  (make-array char-code-limit :initial-element nil))
+  (make-array +format-directive-limit+ :initial-element nil))
 
 (defparameter *default-format-error-control-string* nil)
 (defparameter *default-format-error-offset* nil)
@@ -545,24 +548,24 @@
            (write-string directive stream)
            (interpret-directive-list stream (cdr directives) orig-args args))
           (#-ecl format-directive #+ecl vector
+           (multiple-value-bind
+                 (new-directives new-args)
+               (let* ((code (char-code (format-directive-character directive)))
+                      (function
+                        (and (< code +format-directive-limit+)
+                             (svref *format-directive-interpreters* code)))
+                      (*default-format-error-offset*
+                        (1- (format-directive-end directive))))
+                 (unless function
+                   (error 'format-error
+                          :complaint "Unknown format directive."))
                  (multiple-value-bind
                        (new-directives new-args)
-                     (let ((function
-                            (svref *format-directive-interpreters*
-                                   (char-code (format-directive-character
-                                               directive))))
-                           (*default-format-error-offset*
-                            (1- (format-directive-end directive))))
-                       (unless function
-                         (error 'format-error
-                                :complaint "Unknown format directive."))
-                       (multiple-value-bind
-                             (new-directives new-args)
-                           (funcall function stream directive
-                                    (cdr directives) orig-args args)
-                         (values new-directives new-args)))
-                   (interpret-directive-list stream new-directives
-                                             orig-args new-args)))))
+                     (funcall function stream directive
+                              (cdr directives) orig-args args)
+                   (values new-directives new-args)))
+             (interpret-directive-list stream new-directives
+                                       orig-args new-args)))))
       args))
 
 
@@ -634,11 +637,12 @@
        (values `(write-string ,directive stream)
                more-directives))
       (format-directive
-       (let ((expander
-              (aref *format-directive-expanders*
-                    (char-code (format-directive-character directive))))
-             (*default-format-error-offset*
-              (1- (format-directive-end directive))))
+       (let* ((code (char-code (format-directive-character directive)))
+              (expander
+                (and (< code +format-directive-limit+)
+                     (svref *format-directive-expanders* code)))
+              (*default-format-error-offset*
+                (1- (format-directive-end directive))))
          (if expander
              (funcall expander directive more-directives)
              (error 'format-error
