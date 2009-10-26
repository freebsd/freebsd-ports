
$FreeBSD$

--- lib/tools/emacs/erlang.el.orig
+++ lib/tools/emacs/erlang.el
@@ -3361,7 +3361,7 @@
 		 (erlang-pop stack))
 	       (if (and stack (memq (car (car stack)) '(icr begin)))
 		   (erlang-pop stack))))
-	    ((looking-at "catch[^,\n\\of]*\n")
+	    ((looking-at "\\bcatch[^,\n\\of]*\n")
 	     ;; Must pop top icr layer, `catch' in try/catch
 	     ;;will push a new layer next.
 	     (progn
@@ -3378,10 +3378,10 @@
 	    ;;     (if (and stack (memq (car (car stack)) '(icr begin)))
 	    ;;   (erlang-pop stack))))
 	    )  
-      (cond ((looking-at "\\(if\\|case\\|receive\\|try\\)[^_a-zA-Z0-9]")
+      (cond ((looking-at "\\b\\(if\\|case\\|receive\\|try\\)\\b")
 	     ;; Must push a new icr (if/case/receive) layer.
 	     (erlang-push (list 'icr token (current-column)) stack))
-	    ((looking-at "\\(fun\\)[^_a-zA-Z0-9]")
+	    ((looking-at "\\b\\(fun\\)\\b")
 	     ;; Push a new icr layer if we are defining a `fun'
 	     ;; expression, not when we are refering an existing
 	     ;; function.
@@ -3390,7 +3390,7 @@
 		   (erlang-skip-blank to)
 		   (eq (following-char) ?\())
 		 (erlang-push (list 'icr token (current-column)) stack)))
-	    ((looking-at "\\(begin\\|query\\)[^_a-zA-Z0-9]")
+	    ((looking-at "\\b\\(begin\\|query\\)\\b")
 	     (erlang-push (list 'begin token (current-column)) stack))
 	    ;; In test suites you may want to do something like
 	    ;; ?match(Mem when integer(Mem), mnesia:table_info(Tab,
@@ -3399,22 +3399,22 @@
 	    ;; erlang mode to think the 'when' in the argument is a
 	    ;; "real" when. The following three clauses will avoid
 	    ;; this problem.
-	    ((looking-at "when[^->\.]*if[^->\.]*->"))
-	    ((looking-at "when[^->\.]*case[^->\.]*->"))
-	    ((looking-at "when[^->\.]*receive[^->\.]*->"))
+	    ((looking-at "\\bwhen[^->\.]*if[^->\.]*->"))
+	    ((looking-at "\\bwhen[^->\.]*case[^->\.]*->"))
+	    ((looking-at "\\bwhen[^->\.]*receive[^->\.]*->"))
 	    ;; Normal when case
-	    ((looking-at "when [^->\.]*->")
+	    ((looking-at "\\bwhen [^->\.]*->")
 	     (erlang-push (list 'when token (current-column)) stack))
-	    ((looking-at "after[.]+->")
+	    ((looking-at "\\bafter[.]+->")
 	     (erlang-push (list 'icr token (current-column)) stack))
-	    ((looking-at "after[^_a-zA-Z0-9->]")
-	     ;; Probably in try-statment, fake "->" to get right
+	    ((looking-at "\\bafter\\b")
+	     ;; Probably in try-statement, fake "->" to get right
 	     ;; indentation in erlang-calculate-stack-indent. If it
 	     ;; was an ordinary catch without try, these entries will
 	     ;; be popped of the stack at a later ocaccion.
 	     (erlang-push (list 'icr token (current-column)) stack)
 	     (erlang-push (list '-> token (current-column)) stack))
-	    ((looking-at "catch[^,\n\\of]*\n")
+	    ((looking-at "\\bcatch[^,\n\\of]*\n")
 	     (erlang-push (list 'icr token (current-column)) stack)
 	     (erlang-push (list '-> token (current-column)) stack))
 	    ;;((looking-at "^of$") 
@@ -3469,7 +3469,7 @@
        ((looking-at "->\\|:-")
 	(save-excursion
 	  (back-to-indentation)
-	  (cond ((looking-at "after[^_a-zA-Z0-9]")
+	  (cond ((looking-at "\\bafter\\b")
 		 (erlang-pop stack))))	
 	(if (and stack (eq (car (car stack)) 'when))
 	    (erlang-pop stack))
@@ -3580,7 +3580,7 @@
 	   ;; Return nil or t.
 	   (eq (nth 3 state) 'comment))
 	  ((null stack)
-	   (if (looking-at "when[^_a-zA-Z0-9]")
+	   (if (looking-at "\\bwhen\\b")
 	       erlang-indent-guard
 	     0))
 	  ((eq (car stack-top) '\()
@@ -3608,28 +3608,34 @@
 	   ;;
 	   ;; `after' should be indented to the save level as the
 	   ;; corresponding receive.
-	   (if (looking-at "after[^_a-zA-Z0-9]")
-	       (nth 2 stack-top)
-	     (save-excursion
-	       (goto-char (nth 1 stack-top))
-	       (if (looking-at "case[^_a-zA-Z0-9]")
-		   (+ (nth 2 stack-top) erlang-indent-level)
-		 (skip-chars-forward "a-z")
-		 (skip-chars-forward " \t")
-		 (if (memq (following-char) '(?% ?\n))
-		     (+ (nth 2 stack-top) erlang-indent-level)
-		   (current-column)))))
-	   (if (looking-at "catch[^_a-zA-Z0-9]")
-	       (nth 2 stack-top)
-	     (save-excursion
-	       (goto-char (nth 1 stack-top))
-	       (if (looking-at "case[^_a-zA-Z0-9]")
-		   (+ (nth 2 stack-top) erlang-indent-level)
-		 (skip-chars-forward "a-z")
-		 (skip-chars-forward " \t")
-		 (if (memq (following-char) '(?% ?\n))
-		     (+ (nth 2 stack-top) erlang-indent-level)
-		   (current-column)))))
+	   (let ((top-word (save-excursion
+			     (goto-char (nth 1 stack-top))
+			     (looking-at "\\b\\(\\w+\\)\\b")
+			     (match-string 0))))
+	     (if (and (looking-at "\\bafter\\b")
+		      (not (string= top-word "try")))
+		 (if (string= top-word "case")
+		     (+ (nth 2 stack-top) erlang-indent-level)
+		   (save-excursion
+		     (goto-char (nth 1 stack-top))
+		     (skip-chars-forward "a-z")
+		     (skip-chars-forward " \t")
+		     (if (memq (following-char) '(?% ?\n))
+			 (+ (nth 2 stack-top) erlang-indent-level)
+		       (current-column)))))
+	     (if (or (looking-at "\\bcatch\\b")
+		     (and (looking-at "\\bafter\\b")
+			  (string= top-word "try")))
+		 (nth 2 stack-top)
+	       (if (string= top-word "case")
+		   (+ (nth 2 stack-top) erlang-indent-level)
+		 (save-excursion
+		   (goto-char (nth 1 stack-top))
+		   (skip-chars-forward "a-z")
+		   (skip-chars-forward " \t")
+		   (if (memq (following-char) '(?% ?\n))
+		       (+ (nth 2 stack-top) erlang-indent-level)
+		     (current-column))))))
 	   )
 	  ;; Real indentation, where operators create extra indentation etc.
 	  ((memq (car stack-top) '(-> || begin))
@@ -3638,7 +3644,8 @@
 	   ;; same line. If so use this indentation as base, else
 	   ;; use parent indentation + 2 * level as base.
 	   (let ((off erlang-indent-level)
-		 (skip 2))
+		 (skip 2)
+		 (is-after (looking-at "\\bafter\\b")))
 	     (cond ((null (cdr stack)))	; Top level in function.
 		   ((eq (car stack-top) 'begin)
 		    (setq skip 5))
@@ -3648,7 +3655,9 @@
 	       ;; Look at last thing to see how we are to move relative
 	       ;; to the base.
 	       (goto-char token)
-	       (cond ((looking-at "||\\|,\\|->\\|:-")
+	       (cond ((and is-after (looking-at ","))
+		      off)
+		     ((looking-at "||\\|,\\|->\\|:-")
 		      base)
 		     ((erlang-at-keyword)
 		      (+ (current-column) erlang-indent-level))
@@ -3665,7 +3674,7 @@
 			    ;; the block.  (Here we have a choice: should
 			    ;; the user be forced to reindent continued
 			    ;; lines, or should the "end" be reindented?)
-			    ((looking-at "\\(end\\|after\\|catch\\)[^_a-zA-Z0-9]\\|$")
+			    ((looking-at "\\b\\(end\\|after\\|catch\\)\\b\\|$")
 			     (if (eq (car (car stack)) '->)
 				 (erlang-pop stack))
 			     (if stack
@@ -3680,7 +3689,7 @@
 	   )
 	  ((eq (car stack-top) 'when)
 	   (goto-char (nth 1 stack-top))
-	   (if (looking-at "when\\s *\\($\\|%\\)")
+	   (if (looking-at "\\bwhen\\s *\\($\\|%\\)")
 	       (progn
 		 (erlang-pop stack)
 		 (if (and stack (eq (nth 0 (car stack)) 'icr))
@@ -3757,13 +3766,13 @@
 
 (defun erlang-at-keyword ()
   "Are we looking at an Erlang keyword which will increase indentation?"
-  (looking-at (concat "\\(when\\|if\\|fun\\|case\\|begin\\|query\\|"
-		      "of\\|receive\\|after\\|catch\\)[^_a-zA-Z0-9]")))
+  (looking-at (concat "\\b\\(when\\|if\\|fun\\|case\\|begin\\|query\\|"
+      "of\\|receive\\|after\\|catch\\)\\b")))
 
 (defun erlang-at-operator ()
   "Are we looking at an Erlang operator?"
   (looking-at
-   "\\(bnot\\|div\\|mod\\|band\\|bor\\|bxor\\|bsl\\|bsr\\)[^_a-zA-Z0-9]"))
+   "\\b\\(bnot\\|div\\|mod\\|band\\|bor\\|bxor\\|bsl\\|bsr\\)\\b"))
 
 (defun erlang-comment-indent ()
   "Compute Erlang comment indentation.
@@ -4813,7 +4822,7 @@
 This function is designed to be a member of a criteria list."
   (save-excursion
     (erlang-skip-blank)
-    (looking-at "end[^_a-zA-Z0-9]")))
+    (looking-at "\\bend\\b")))
 
 
 ;; Erlang tags support which is aware of erlang modules.
