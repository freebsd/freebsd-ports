--- psgml-parse.el.orig	2012-08-04 11:37:03.000000000 +0900
+++ psgml-parse.el	2012-08-04 11:37:19.000000000 +0900
@@ -329,28 +329,28 @@
 ;;(progn (set-syntax-table xml-parser-syntax) (describe-syntax))
 
 (defmacro sgml-with-parser-syntax (&rest body)
-  (` (let ((normal-syntax-table (syntax-table))
+  `(let ((normal-syntax-table (syntax-table))
            (cb (current-buffer)))
        (set-syntax-table (if sgml-xml-p xml-parser-syntax sgml-parser-syntax))
        (unwind-protect
-	   (progn (,@ body))
+	   (progn ,@body)
          (setq sgml-last-buffer (current-buffer))
          (set-buffer cb)
-	 (set-syntax-table normal-syntax-table)))))
+	 (set-syntax-table normal-syntax-table))))
 
 (defmacro sgml-with-parser-syntax-ro (&rest body)
   ;; Should only be used for parsing ....
-  (` (let ((normal-syntax-table (syntax-table))
+  `(let ((normal-syntax-table (syntax-table))
            (cb (current-buffer))
            (buffer-modified (buffer-modified-p)))
        (set-syntax-table (if sgml-xml-p xml-parser-syntax sgml-parser-syntax))
        (unwind-protect
-	   (progn (,@ body))
+	   (progn ,@body)
          (setq sgml-last-buffer (current-buffer))
          (set-buffer cb)
 	 (set-syntax-table normal-syntax-table)
          (sgml-restore-buffer-modified-p buffer-modified)
-         (sgml-debug "Restoring buffer mod: %s" buffer-modified)))))
+         (sgml-debug "Restoring buffer mod: %s" buffer-modified))))
 
 (defun sgml-set-buffer-multibyte (flag)
   (cond ((featurep 'xemacs)
@@ -361,7 +361,7 @@
               default-enable-multibyte-characters
             flag)))
 	((boundp 'MULE)
-         (set 'mc-flag flag))
+         (if (boundp 'mc-flag) (set 'mc-flag flag)))
         (t
          flag)))
 ;; Probably better.  -- fx
@@ -428,21 +428,21 @@
 ;;move: (token . node)
 
 (defmacro sgml-make-move (token node)
-  (` (cons (, token) (, node))))
+  `(cons ,token ,node))
 
 (defmacro sgml-move-token (x)
-  (` (car (, x))))
+  `(car ,x))
 
 (defmacro sgml-move-dest (x)
-  (` (cdr (, x))))
+  `(cdr ,x))
 
 ;; set of moves: list of moves
 
 (defmacro sgml-add-move-to-set (token node set)
-  (`(cons (cons (, token) (, node)) (, set))))
+  `(cons (cons ,token ,node) ,set))
 
 (defmacro sgml-moves-lookup (token set)
-  (` (assq (, token) (, set))))
+  `(assq ,token ,set))
 
 ;; normal-state: ('normal-state opts . reqs)
 
@@ -450,16 +450,16 @@
   (cons 'normal-state (cons nil nil)))
 
 (defmacro sgml-normal-state-p (s)
-  (` (eq (car (, s)) 'normal-state)))
+  `(eq (car ,s) 'normal-state))
 
 (defmacro sgml-state-opts (s)
-  (` (cadr (, s))))
+  `(cadr ,s))
 
 (defmacro sgml-state-reqs (s)
-  (` (cddr (, s))))
+  `(cddr ,s))
 
 (defmacro sgml-state-final-p (s)
-  (`(null (sgml-state-reqs (, s)))))
+  `(null (sgml-state-reqs ,s)))
 
 ;; adding moves
 ;; *** Should these functions check for ambiguity?
@@ -507,10 +507,10 @@
   (cons next dfas))
 
 (defmacro sgml-and-node-next (n)
-  (` (car (, n))))
+  `(car ,n))
 
 (defmacro sgml-and-node-dfas (n)
-  (` (cdr (, n))))
+  `(cdr ,n))
 
 
 ;;; Using states
@@ -903,8 +903,8 @@
   (cons
    'progn
    (loop for n in names collect
-	 (`(defmacro (, (intern (format "sgml-eltype-%s" n))) (et)
-	     (list 'get et ''(, n)))))))
+	 `(defmacro ,(intern (format "sgml-eltype-%s" n)) (et)
+	     (list 'get et '',n)))))
 
 (sgml-prop-fields
  ;;flags			; optional tags and mixed
@@ -919,7 +919,7 @@
  )
 
 (defmacro sgml-eltype-flags (et)
-  (` (symbol-value (, et))))
+  `(symbol-value ,et))
 
 (defun sgml-eltype-model (et)
   (if (fboundp et)
@@ -966,7 +966,7 @@
   "Get application data from element type ET with name PROP.
 PROP should be a symbol, reserved names are: flags, model, attlist,
 includes, excludes, conref-regexp, mixed, stag-optional, etag-optional."
-  (` (get (, et) (, prop))))
+  ` (get ,et ,prop))
 
 (defun sgml-eltype-all-miscdata (et)
   (loop for p on (symbol-plist et) by (function cddr)
@@ -1059,7 +1059,7 @@
 ;;; Wing addition
 (defmacro sgml-char-int (ch)
   (if (fboundp 'char-int)
-      (` (char-int (, ch)))
+      `(char-int ,ch)
     ch))
 
 (defsubst sgml-read-octet ()
@@ -1434,51 +1434,51 @@
 	   (setq context '(t)))
 	  ((not (listp context))
 	   (setq context (list context))))
-    (`(if (and				; This and checks that characters
+    `(if (and				; This and checks that characters
 					; of the delimiter
-	   (,@(loop for i from 0 below (length ds) collect
-		    (` (eq (, (aref ds i))
-			   (sgml-following-char (, (+ i offset)))))))
+	   ,@(loop for i from 0 below (length ds) collect
+		    `(eq ,(aref ds i)
+			   (sgml-following-char ,(+ i offset))))
 	   (or
-	    (,@(loop
+	    ,@(loop
 		for c in context collect ; context check
 		(cond
 		 ((eq c 'nmstart)	; name start character
-		  (`(sgml-startnm-char
-		     (or (sgml-following-char (, (length ds))) 0))))
+		  `(sgml-startnm-char
+		     (or (sgml-following-char ,(length ds)) 0)))
 		 ((eq c 'stagc)
-		  (`(and sgml-current-shorttag
-			 (sgml-is-delim "TAGC" nil nil (, (length ds))))))
+		  `(and sgml-current-shorttag
+			 (sgml-is-delim "TAGC" nil nil ,(length ds))))
 		 ((eq c 'digit)
-		  (`(memq (sgml-following-char (, (length ds)))
-			  '(?0 ?1 ?2 ?3 ?4 ?5 ?6 ?7 ?8 ?9))))
+		  `(memq (sgml-following-char ,(length ds))
+			  '(?0 ?1 ?2 ?3 ?4 ?5 ?6 ?7 ?8 ?9)))
 		 ((stringp c)
-		  (`(sgml-is-delim (, c) nil nil (, (length ds)))))
+		  `(sgml-is-delim ,c nil nil ,(length ds)))
 		 ((eq c t))
 		 (t (error "Context type: %s" c))))
-	       )))
+	       ))
 	  
 	  (progn			; Do operations if delimiter found
-	    (,@ (if move (`((forward-char (, (length ds)))))))
-	    (,@ (if (not (eq move 'check))
-		    '(t))))
-	(,@ (if (eq move 'check)
-		(`((sgml-delimiter-parse-error (, delim))))))))))
+	    ,@(if move `((forward-char ,(length ds))))
+	    ,@(if (not (eq move 'check))
+		    '(t)))
+	,@(if (eq move 'check)
+		`((sgml-delimiter-parse-error ,delim))))))
 
 (defmacro sgml-following-char (n)
   (cond ((zerop n)  '(following-char))
 	((= n 1)    '(char-after (1+ (point))))
-	(t          (` (char-after (+ (, n) (point)))))))
+	(t          `(char-after (+ ,n (point))))))
 
 (defun sgml-delimiter-parse-error (delim)
   (sgml-parse-error "Delimiter %s (%s) expected"
 		    delim (sgml-get-delim-string delim)))
 
 (defmacro sgml-parse-delim (delim &optional context)
-  (`(sgml-is-delim (, delim) (, context) move)))
+  `(sgml-is-delim ,delim ,context move))
 
 (defmacro sgml-check-delim (delim &optional context)
-  (`(sgml-is-delim (, delim) (, context) check)))
+  `(sgml-is-delim ,delim ,context check))
 
 (defmacro sgml-skip-upto (delim)
   "Skip until the delimiter or first char of one of the delimiters.
@@ -1502,8 +1502,8 @@
     (let ((ds (sgml-get-delim-string (upcase (format "%s" delim)))))
       (if (= 1 (length ds))
 	  (list 'skip-chars-forward (concat "^" ds))
-	(`(and (search-forward (, ds) nil t)
-	       (backward-char (, (length ds))))))))))
+	`(and (search-forward ,ds nil t)
+	       (backward-char ,(length ds))))))))
 
 
 ;;(macroexpand '(sgml-is-delim mdo))
@@ -1520,22 +1520,22 @@
 ;;;                aproporiate value.
 
 (defmacro sgml-parse-char (char)
-  (` (cond ((eq (, char) (following-char))
+  `(cond ((eq ,char (following-char))
 	    (forward-char 1)
-	    t))))
+	    t)))
 
 (defmacro sgml-parse-chars (char1 char2 &optional char3)
   "Parse two or three chars; return nil if can't."
   (if (null char3)
-      (` (cond ((and (eq (, char1) (following-char))
-		 (eq (, char2) (char-after (1+ (point)))))
+      `(cond ((and (eq ,char1 (following-char))
+		 (eq ,char2 (char-after (1+ (point)))))
 	    (forward-char 2)
-	    t)))
-    (` (cond ((and (eq (, char1) (following-char))
-		 (eq (, char2) (char-after (1+ (point))))
-		 (eq (, char3) (char-after (1+ (1+ (point))))))
+	    t))
+    `(cond ((and (eq ,char1 (following-char))
+		 (eq ,char2 (char-after (1+ (point))))
+		 (eq ,char3 (char-after (1+ (1+ (point))))))
 	    (forward-char 3)
-	    t)))))
+	    t))))
 
 (defun sgml-check-char (char)
   (cond ((not (sgml-parse-char char))
@@ -1546,7 +1546,7 @@
       (sgml-parse-char ?\r)))
 
 (defmacro sgml-startnm-char (c)
-  (` (eq ?w (char-syntax (, c)))))
+  `(eq ?w (char-syntax ,c)))
 
 (defsubst sgml-startnm-char-next ()
   (and (not (eobp))
@@ -1693,11 +1693,11 @@
 (define-compiler-macro sgml-parse-name (&whole form &optional entity-name)
   (cond
    ((memq entity-name '(nil t))
-    (` (if (sgml-startnm-char-next)
-	   ((, (if entity-name 'sgml-entity-case 'sgml-general-case))
+    `(if (sgml-startnm-char-next)
+	   (,(if entity-name 'sgml-entity-case 'sgml-general-case)
 	    (buffer-substring-no-properties (point)
 					    (progn (skip-syntax-forward "w_")
-						   (point)))))))
+						   (point))))))
    (t
     form)))
 
@@ -1827,8 +1827,8 @@
 With optional NAME, RNI must be followed by NAME."
   (cond
    (name
-    (` (if (sgml-parse-delim "RNI")
-	   (sgml-check-token (, name)))))
+    `(if (sgml-parse-delim "RNI")
+	   (sgml-check-token ,name)))
    (t '(sgml-parse-delim "RNI"))))
 
 (defun sgml-check-token (name)
@@ -2733,11 +2733,11 @@
   (let ((macs nil))
     (while fields
       (push
-       (` (defmacro (, (intern (format "%s-%s" dest (car fields)))) (element)
-	    (, (format "Return %s field of ELEMENT." (car fields)))
+       `(defmacro ,(intern (format "%s-%s" dest (car fields))) (element)
+	    ,(format "Return %s field of ELEMENT." (car fields))
 	    (list
-	     '(, (intern (format "%s-%s" orig (car fields))))
-	     element)))
+	     ',(intern (format "%s-%s" orig (car fields)))
+	     element))
        macs)
       (setq fields (cdr fields)))
     (cons 'progn macs)))
@@ -2775,7 +2775,7 @@
 
 (defmacro sgml-element-stag-optional (element)
   "True if start-tag of ELEMENT is omissible."
-  (`(sgml-eltype-stag-optional (sgml-tree-eltype (, element)))))
+  `(sgml-eltype-stag-optional (sgml-tree-eltype ,element)))
 
 (defsubst sgml-element-etag-optional (element)
   "True if end-tag of ELEMENT is omissible."
@@ -2929,8 +2929,10 @@
 
 (defun sgml-set-initial-state (dtd)
   "Set initial state of parsing."
-  (make-local-hook 'before-change-functions)
-  (make-local-hook 'after-change-functions)
+  (if (fboundp 'make-local-hook)
+    (progn
+      (make-local-hook 'before-change-functions)
+      (make-local-hook 'after-change-functions)))
   (add-hook 'before-change-functions 'sgml-note-change-at nil 'local)
   (add-hook 'after-change-functions 'sgml-set-face-after-change nil 'local)
   (sgml-set-active-dtd-indicator (sgml-dtd-doctype dtd))
@@ -3504,7 +3506,7 @@
 Also move point.  Return nil, either if no shortref or undefined."
 
   (macrolet
-      ((delim (x) (` (aref map (, (sgml-shortref-index x))))))
+      ((delim (x) `(aref map ,(sgml-shortref-index x))))
     (let ((i (if nobol 1 0)))
       (while (numberp i)
 	(setq i
