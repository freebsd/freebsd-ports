--- lisp/lookup-types.el.orig	2026-09-07 07:18:56 UTC
+++ lisp/lookup-types.el
@@ -471,7 +471,7 @@ Each DICT-SPEC consists of (dict-id :option val ....).
 (defun lookup-regular-search (dictionary query)
   (lookup-dictionary-command dictionary :search query))
 
-(defconst lookup-obarray (make-vector 1511 nil))
+(defconst lookup-obarray (obarray-make 1511))
 
 (defun lookup-dictionary-search-cache-get (dictionary query)
   (let ((method (lookup-query-method query))
@@ -757,7 +757,7 @@ the present circumstances. TYPE is a symbol like `xbm'
 ;; gaiji table
 
 (defun lookup-make-gaiji-table ()
-  (make-vector 377 0))
+  (obarray-make 377))
 
 (defsubst lookup-gaiji-table-set (table code gaiji)
   (set (intern code table) gaiji))
