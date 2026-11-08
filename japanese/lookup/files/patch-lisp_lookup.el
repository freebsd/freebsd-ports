--- lisp/lookup.el.orig	2026-09-07 07:19:31 UTC
+++ lisp/lookup.el
@@ -721,7 +721,7 @@ If there is no session, default module will be returne
 
 (defun lookup-put-entry (entry)
   (unless lookup-entry-table
-    (setq lookup-entry-table (make-vector 377 0)))
+    (setq lookup-entry-table (obarray-make 377)))
   (set (intern (lookup-entry-id entry) lookup-entry-table) entry))
 
 (defun lookup-get-entry (id)
