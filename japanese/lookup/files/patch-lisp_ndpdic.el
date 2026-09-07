--- lisp/ndpdic.el.orig	2026-09-07 07:24:09 UTC
+++ lisp/ndpdic.el
@@ -214,7 +214,7 @@
         (setf (ndpdic-derefid o)      (char 8))
         (setf (ndpdic-dummy o)        (char 24))
         ;;
-        (setf (ndpdic-block-index o) (make-vector (ndpdic-nindex2 o) nil))
+        (setf (ndpdic-block-index o) (obarray-make (ndpdic-nindex2 o)))
         (setf (ndpdic-block-entries-hash o) (make-hash-table :test 'equal))
         )
       (with-temp-buffer
