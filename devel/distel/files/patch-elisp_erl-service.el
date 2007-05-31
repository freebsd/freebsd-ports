
$FreeBSD$

--- elisp/erl-service.el.orig
+++ elisp/erl-service.el
@@ -783,11 +783,11 @@
 (defun erl-search-function (function arity)
   "Goto the definition of FUNCTION/ARITY in the current buffer."
   (let ((origin (point))
-	(str (concat "\n" function "("))
+	(str (concat "\n" function " *("))
 	(searching t))
     (goto-char (point-min))
     (while searching
-      (cond ((search-forward str nil t)
+      (cond ((search-forward-regexp str nil t)
 	     (backward-char)
 	     (when (or (null arity)
 		       (eq (erl-arity-at-point) arity))
