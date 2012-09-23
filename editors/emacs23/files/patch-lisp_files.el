
$FreeBSD$

--- lisp/files.el.orig
+++ lisp/files.el
@@ -2986,11 +2986,16 @@
 	      ;; Obey `enable-local-eval'.
 	      ((eq var 'eval)
 	       (when enable-local-eval
-		 (push elt all-vars)
-		 (or (eq enable-local-eval t)
-		     (hack-one-local-variable-eval-safep (eval (quote val)))
-		     (safe-local-variable-p var val)
-		     (push elt unsafe-vars))))
+		 (let ((safe (or (hack-one-local-variable-eval-safep
+				  (eval (quote val)))
+				 ;; In case previously marked safe (bug#5636).
+				 (safe-local-variable-p var val))))
+		   ;; If not safe and e-l-v = :safe, ignore totally.
+		   (when (or safe (not (eq enable-local-variables :safe)))
+		     (push elt all-vars)
+		     (or (eq enable-local-eval t)
+			 safe
+			 (push elt unsafe-vars))))))
 	      ;; Ignore duplicates (except `mode') in the present list.
 	      ((and (assq var all-vars) (not (eq var 'mode))) nil)
 	      ;; Accept known-safe variables.
