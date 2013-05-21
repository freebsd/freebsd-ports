--- gfunc.el.orig	2013-05-21 18:33:44.886328696 +0900
+++ gfunc.el	2013-05-21 18:35:12.044799983 +0900
@@ -109,14 +109,12 @@
 BODY is typically a set of `gfunc-def', and DISPATCHERS-VAR is used
 as their dispatchers.
 This macro cannot be nested."
+  ;; Be careful to etc/NEWS in Emacs 24.3 or
+  ;; http://www.masteringemacs.org/articles/2013/03/11/whats-new-emacs-24-3/
+  ;; "Emacs tries to macroexpand interpreted (non-compiled) files during load."
+  (setq *gfunc-dispatchers-var* dispatchers-var)
   `(eval-and-compile
-     ;; I want to use let instead of setq.
-     ;; But, let doesn't work when this file is byte-compiled.
-     ;; I don't understand the problem around macro and byte-compilation.
-     (setq *gfunc-dispatchers-var* (quote ,dispatchers-var))
      ,@body))
-;;      (let ((*gfunc-dispatchers-var* (quote ,dispatchers-var)))
-;;        ,@body)))
 
 (provide 'gfunc)
 
