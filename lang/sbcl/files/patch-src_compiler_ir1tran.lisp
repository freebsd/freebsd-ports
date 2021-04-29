--- src/compiler/ir1tran.lisp.orig	2021-04-28 20:54:30 UTC
+++ src/compiler/ir1tran.lisp
@@ -329,7 +329,7 @@
 ;;; CONSTANT might be circular. We also check that the constant (and
 ;;; any subparts) are dumpable at all.
 (defun ensure-externalizable (constant)
-  (declare (inline alloc-xset))
+  (declare #-sb-xc-host (inline alloc-xset))
   (dx-let ((xset (alloc-xset)))
     (named-let grovel ((value constant))
       ;; Unless VALUE is an object which which can't contain other objects,
@@ -386,7 +386,7 @@
 ;;; A constant is trivially externalizable if it involves no INSTANCE types
 ;;; or any un-dumpable object.
 (defun trivially-externalizable-p (constant)
-  (declare (inline alloc-xset))
+  (declare #-sb-xc-host (inline alloc-xset))
   (dx-let ((xset (alloc-xset)))
     (named-let ok ((value constant))
       (if (or (dumpable-leaflike-p value) (xset-member-p value xset))
