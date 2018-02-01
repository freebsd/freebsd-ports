--- poe.el.orig	2008-09-06 15:16:14 UTC
+++ poe.el
@@ -38,22 +38,22 @@
 ;;;
 
 (static-when (= emacs-major-version 18)
-  (require 'poe-18))
+	     (require 'poe-18))
 
 ;; Some ancient version of XEmacs did not provide 'xemacs.
 (static-when (string-match "XEmacs" emacs-version)
-  (provide 'xemacs))
+	     (provide 'xemacs))
 
 ;; `file-coding' was appeared in the spring of 1998, just before XEmacs
 ;; 21.0. Therefore it is not provided in XEmacs with MULE versions 20.4
 ;; or earlier.
 (static-when (featurep 'xemacs)
-  ;; must be load-time check to share .elc between w/ MULE and w/o MULE.
-  (when (featurep 'mule)
-    (provide 'file-coding)))
+	     ;; must be load-time check to share .elc between w/ MULE and w/o MULE.
+	     (when (featurep 'mule)
+	       (provide 'file-coding)))
 
 (static-when (featurep 'xemacs)
-  (require 'poe-xemacs))
+	     (require 'poe-xemacs))
 
 ;; must be load-time check to share .elc between different systems.
 (or (fboundp 'open-network-stream)
@@ -66,18 +66,18 @@
 ;; Emacs 20.3 and earlier: (require FEATURE &optional FILENAME)
 ;; Emacs 20.4 and later: (require FEATURE &optional FILENAME NOERROR)
 (static-condition-case nil
-    ;; compile-time check.
-    (progn
-      (require 'nofeature "nofile" 'noerror)
-      (if (get 'require 'defun-maybe)
-	  (error "`require' is already redefined")))
-  (error
-   ;; load-time check.
-   (or (fboundp 'si:require)
-       (progn
-	 (fset 'si:require (symbol-function 'require))
-	 (defun require (feature &optional filename noerror)
-	   "\
+		       ;; compile-time check.
+		       (progn
+			 (require 'nofeature "nofile" 'noerror)
+			 (if (get 'require 'defun-maybe)
+			     (error "`require' is already redefined")))
+		       (error
+			;; load-time check.
+			(or (fboundp 'si:require)
+			    (progn
+			      (fset 'si:require (symbol-function 'require))
+			      (defun require (feature &optional filename noerror)
+				"\
 If feature FEATURE is not loaded, load it from FILENAME.
 If FEATURE is not a member of the list `features', then the feature
 is not loaded; so load the file FILENAME.
@@ -86,14 +86,14 @@ but in this case `load' insists on addin
 If the optional third argument NOERROR is non-nil,
 then return nil if the file is not found.
 Normally the return value is FEATURE."
-	   (if noerror
-	       (condition-case nil
-		   (si:require feature filename)
-		 (file-error))
-	     (si:require feature filename)))
-	 ;; for `load-history'.
-	 (setq current-load-list (cons 'require current-load-list))
-	 (put 'require 'defun-maybe t)))))
+				(if noerror
+				    (condition-case nil
+					(si:require feature filename)
+				      (file-error))
+				  (si:require feature filename)))
+			      ;; for `load-history'.
+			      (setq current-load-list (cons 'require current-load-list))
+			      (put 'require 'defun-maybe t)))))
 
 ;; Emacs 19.29 and later: (plist-get PLIST PROP)
 ;; (defun-maybe plist-get (plist prop)
@@ -103,21 +103,21 @@ Normally the return value is FEATURE."
 ;;   (car (cdr plist)))
 (static-unless (and (fboundp 'plist-get)
 		    (not (get 'plist-get 'defun-maybe)))
-  (or (fboundp 'plist-get)
-      (progn
-	(defvar plist-get-internal-symbol)
-	(defun plist-get (plist prop)
-	  "\
+	       (or (fboundp 'plist-get)
+		   (progn
+		     (defvar plist-get-internal-symbol)
+		     (defun plist-get (plist prop)
+		       "\
 Extract a value from a property list.
 PLIST is a property list, which is a list of the form
 \(PROP1 VALUE1 PROP2 VALUE2...\).  This function returns the value
 corresponding to the given PROP, or nil if PROP is not
 one of the properties on the list."
-	  (setplist 'plist-get-internal-symbol plist)
-	  (get 'plist-get-internal-symbol prop))
-	;; for `load-history'.
-	(setq current-load-list (cons 'plist-get current-load-list))
-	(put 'plist-get 'defun-maybe t))))
+		       (setplist 'plist-get-internal-symbol plist)
+		       (get 'plist-get-internal-symbol prop))
+		     ;; for `load-history'.
+		     (setq current-load-list (cons 'plist-get current-load-list))
+		     (put 'plist-get 'defun-maybe t))))
 
 ;; Emacs 19.29 and later: (plist-put PLIST PROP VAL)
 ;; (defun-maybe plist-put (plist prop val)
@@ -138,11 +138,11 @@ one of the properties on the list."
 ;;         (list prop val)))))
 (static-unless (and (fboundp 'plist-put)
 		    (not (get 'plist-put 'defun-maybe)))
-  (or (fboundp 'plist-put)
-      (progn
-	(defvar plist-put-internal-symbol)
-	(defun plist-put (plist prop val)
-	  "\
+	       (or (fboundp 'plist-put)
+		   (progn
+		     (defvar plist-put-internal-symbol)
+		     (defun plist-put (plist prop val)
+		       "\
 Change value in PLIST of PROP to VAL.
 PLIST is a property list, which is a list of the form
 \(PROP1 VALUE1 PROP2 VALUE2 ...\).  PROP is a symbol and VAL is any object.
@@ -150,12 +150,12 @@ If PROP is already a property on the lis
 otherwise the new PROP VAL pair is added.  The new plist is returned;
 use `\(setq x \(plist-put x prop val\)\)' to be sure to use the new value.
 The PLIST is modified by side effects."
-	  (setplist 'plist-put-internal-symbol plist)
-	  (put 'plist-put-internal-symbol prop val)
-	  (symbol-plist 'plist-put-internal-symbol))
-	;; for `load-history'.
-	(setq current-load-list (cons 'plist-put current-load-list))
-	(put 'plist-put 'defun-maybe t))))
+		       (setplist 'plist-put-internal-symbol plist)
+		       (put 'plist-put-internal-symbol prop val)
+		       (symbol-plist 'plist-put-internal-symbol))
+		     ;; for `load-history'.
+		     (setq current-load-list (cons 'plist-put current-load-list))
+		     (put 'plist-put 'defun-maybe t))))
 
 ;; Emacs 19.23 and later: (minibuffer-prompt-width)
 (defun-maybe minibuffer-prompt-width ()
@@ -170,16 +170,16 @@ The PLIST is modified by side effects."
 		   (>= emacs-major-version 20)
 		   (and (= emacs-major-version 19)
 			(>= emacs-minor-version 29)))
-  (or (fboundp 'si:read-string)
-      (progn
-	(fset 'si:read-string (symbol-function 'read-string))
-	(defun read-string (prompt &optional initial-input history)
-	  "\
+	       (or (fboundp 'si:read-string)
+		   (progn
+		     (fset 'si:read-string (symbol-function 'read-string))
+		     (defun read-string (prompt &optional initial-input history)
+		       "\
 Read a string from the minibuffer, prompting with string PROMPT.
 If non-nil, second arg INITIAL-INPUT is a string to insert before reading.
 The third arg HISTORY, is dummy for compatibility.
 See `read-from-minibuffer' for details of HISTORY argument."
-	  (si:read-string prompt initial-input)))))
+		       (si:read-string prompt initial-input)))))
 
 ;; (completing-read prompt table &optional
 ;; FSF Emacs
@@ -203,8 +203,8 @@ See `read-from-minibuffer' for details o
 	(fset 'si:completing-read (symbol-function 'completing-read))
 	(defun completing-read
 	  (prompt table &optional predicate require-match init
-		                  hist def)
-	"Read a string in the minibuffer, with completion.
+		  hist def)
+	  "Read a string in the minibuffer, with completion.
 PROMPT is a string to prompt with; normally it ends in a colon and a space.
 TABLE is an alist whose elements' cars are strings, or an obarray.
 PREDICATE limits completion to a subset of TABLE.
@@ -225,10 +225,10 @@ DEF, if non-nil, is the default value.
 
 Completion ignores case if the ambient value of
   `completion-ignore-case' is non-nil."
-	(let ((string (si:completing-read prompt table predicate
-					  require-match init)))
-	  (if (and (string= string "") def)
-	      def string))))))
+	  (let ((string (si:completing-read prompt table predicate
+					    require-match init)))
+	    (if (and (string= string "") def)
+		def string))))))
  ;; add 'def' argument.
  ((or (and (featurep 'xemacs)
 	   (or (and (eq emacs-major-version 21)
@@ -240,8 +240,8 @@ Completion ignores case if the ambient v
 	(fset 'si:completing-read (symbol-function 'completing-read))
 	(defun completing-read
 	  (prompt table &optional predicate require-match init
-		                  hist def)
-	"Read a string in the minibuffer, with completion.
+		  hist def)
+	  "Read a string in the minibuffer, with completion.
 PROMPT is a string to prompt with; normally it ends in a colon and a space.
 TABLE is an alist whose elements' cars are strings, or an obarray.
 PREDICATE limits completion to a subset of TABLE.
@@ -269,10 +269,10 @@ DEF, if non-nil, is the default value.
 
 Completion ignores case if the ambient value of
   `completion-ignore-case' is non-nil."
-	(let ((string (si:completing-read prompt table predicate
-					  require-match init hist)))
-	  (if (and (string= string "") def)
-	      def string)))))))
+	  (let ((string (si:completing-read prompt table predicate
+					    require-match init hist)))
+	    (if (and (string= string "") def)
+		def string)))))))
 
 ;; v18:	(string-to-int STRING)
 ;; v19:	(string-to-number STRING)
@@ -281,24 +281,24 @@ Completion ignores case if the ambient v
 ;; XXX: `string-to-number' of Emacs 20.3 and earlier is broken.
 ;;	(string-to-number "1e1" 16) => 10.0, should be 481.
 (static-condition-case nil
-    ;; compile-time check.
-    (if (= (string-to-number "1e1" 16) 481)
-	(if (get 'string-to-number 'defun-maybe)
-	    (error "`string-to-number' is already redefined"))
-      (error "`string-to-number' is broken"))
-  (error
-   ;; load-time check.
-   (or (fboundp 'si:string-to-number)
-       (progn
-	 (if (fboundp 'string-to-number)
-	     (fset 'si:string-to-number (symbol-function 'string-to-number))
-	   (fset 'si:string-to-number (symbol-function 'string-to-int))
-	   ;; XXX: In v18, this causes infinite loop while byte-compiling.
-	   ;; (defalias 'string-to-int 'string-to-number)
-	   )
-	 (put 'string-to-number 'defun-maybe t)
-	 (defun string-to-number (string &optional base)
-	   "\
+		       ;; compile-time check.
+		       (if (= (string-to-number "1e1" 16) 481)
+			   (if (get 'string-to-number 'defun-maybe)
+			       (error "`string-to-number' is already redefined"))
+			 (error "`string-to-number' is broken"))
+		       (error
+			;; load-time check.
+			(or (fboundp 'si:string-to-number)
+			    (progn
+			      (if (fboundp 'string-to-number)
+				  (fset 'si:string-to-number (symbol-function 'string-to-number))
+				(fset 'si:string-to-number (symbol-function 'string-to-int))
+				;; XXX: In v18, this causes infinite loop while byte-compiling.
+				;; (defalias 'string-to-int 'string-to-number)
+				)
+			      (put 'string-to-number 'defun-maybe t)
+			      (defun string-to-number (string &optional base)
+				"\
 Convert STRING to a number by parsing it as a decimal number.
 This parses both integers and floating point numbers.
 It ignores leading spaces and tabs.
@@ -306,39 +306,39 @@ It ignores leading spaces and tabs.
 If BASE, interpret STRING as a number in that base.  If BASE isn't
 present, base 10 is used.  BASE must be between 2 and 16 (inclusive).
 If the base used is not 10, floating point is not recognized."
-	   (if (or (null base) (= base 10))
-	       (si:string-to-number string)
-	     (if (or (< base 2)(> base 16))
-		 (signal 'args-out-of-range (cons base nil)))
-	     (let ((len (length string))
-		   (pos 0))
-	       ;; skip leading whitespace.
-	       (while (and (< pos len)
-			   (memq (aref string pos) '(?\  ?\t)))
-		 (setq pos (1+ pos)))
-	       (if (= pos len)
-		   0
-		 (let ((number 0)(negative 1)
-		       chr num)
-		   (if (eq (aref string pos) ?-)
-		       (setq negative -1
-			     pos (1+ pos))
-		     (if (eq (aref string pos) ?+)
-			 (setq pos (1+ pos))))
-		   (while (and (< pos len)
-			       (setq chr (aref string pos)
-				     num (cond
-					  ((and (<= ?0 chr)(<= chr ?9))
-					   (- chr ?0))
-					  ((and (<= ?A chr)(<= chr ?F))
-					   (+ (- chr ?A) 10))
-					  ((and (<= ?a chr)(<= chr ?f))
-					   (+ (- chr ?a) 10))
-					  (t nil)))
-			       (< num base))
-		     (setq number (+ (* number base) num)
-			   pos (1+ pos)))
-		   (* negative number))))))))))
+				(if (or (null base) (= base 10))
+				    (si:string-to-number string)
+				  (if (or (< base 2)(> base 16))
+				      (signal 'args-out-of-range (cons base nil)))
+				  (let ((len (length string))
+					(pos 0))
+				    ;; skip leading whitespace.
+				    (while (and (< pos len)
+						(memq (aref string pos) '(?\  ?\t)))
+				      (setq pos (1+ pos)))
+				    (if (= pos len)
+					0
+				      (let ((number 0)(negative 1)
+					    chr num)
+					(if (eq (aref string pos) ?-)
+					    (setq negative -1
+						  pos (1+ pos))
+					  (if (eq (aref string pos) ?+)
+					      (setq pos (1+ pos))))
+					(while (and (< pos len)
+						    (setq chr (aref string pos)
+							  num (cond
+							       ((and (<= ?0 chr)(<= chr ?9))
+								(- chr ?0))
+							       ((and (<= ?A chr)(<= chr ?F))
+								(+ (- chr ?A) 10))
+							       ((and (<= ?a chr)(<= chr ?f))
+								(+ (- chr ?a) 10))
+							       (t nil)))
+						    (< num base))
+					  (setq number (+ (* number base) num)
+						pos (1+ pos)))
+					(* negative number))))))))))
 
 ;; Emacs 20.1 and 20.2: (concat-chars &rest CHARS)
 ;; Emacs 20.3/XEmacs 21.0 and later: (string &rest CHARS)
@@ -362,130 +362,130 @@ If the base used is not 10, floating poi
 ;; Mule: (char-before POS)
 ;; v20: (char-before &optional POS)
 (static-condition-case nil
-    ;; compile-time check.
-    (progn
-      (char-before)
-      (if (get 'char-before 'defun-maybe)
-	  (error "`char-before' is already defined")))
-  (wrong-number-of-arguments            ; Mule.
-   ;; load-time check.
-   (or (fboundp 'si:char-before)
-       (progn
-         (fset 'si:char-before (symbol-function 'char-before))
-         (put 'char-before 'defun-maybe t)
-         ;; takes IGNORED for backward compatibility.
-         (defun char-before (&optional pos ignored)
-           "\
+		       ;; compile-time check.
+		       (progn
+			 (char-before)
+			 (if (get 'char-before 'defun-maybe)
+			     (error "`char-before' is already defined")))
+		       (wrong-number-of-arguments            ; Mule.
+			;; load-time check.
+			(or (fboundp 'si:char-before)
+			    (progn
+			      (fset 'si:char-before (symbol-function 'char-before))
+			      (put 'char-before 'defun-maybe t)
+			      ;; takes IGNORED for backward compatibility.
+			      (defun char-before (&optional pos ignored)
+				"\
 Return character in current buffer preceding position POS.
 POS is an integer or a buffer pointer.
 If POS is out of range, the value is nil."
-           (si:char-before (or pos (point)))))))
-  (void-function                        ; non-Mule.
-   ;; load-time check.
-   (defun-maybe char-before (&optional pos)
-     "\
+				(si:char-before (or pos (point)))))))
+		       (void-function                        ; non-Mule.
+			;; load-time check.
+			(defun-maybe char-before (&optional pos)
+			  "\
 Return character in current buffer preceding position POS.
 POS is an integer or a buffer pointer.
 If POS is out of range, the value is nil."
-     (if pos
-         (save-excursion
-           (and (= (goto-char pos) (point))
-                (not (bobp))
-                (preceding-char)))
-       (and (not (bobp))
-            (preceding-char)))))
-  (error                                ; found our definition at compile-time.
-   ;; load-time check.
-   (condition-case nil
-       (char-before)
-     (wrong-number-of-arguments         ; Mule.
-      (or (fboundp 'si:char-before)
-          (progn
-            (fset 'si:char-before (symbol-function 'char-before))
-            (put 'char-before 'defun-maybe t)
-            ;; takes IGNORED for backward compatibility.
-            (defun char-before (&optional pos ignored)
-              "\
+			  (if pos
+			      (save-excursion
+				(and (= (goto-char pos) (point))
+				     (not (bobp))
+				     (preceding-char)))
+			    (and (not (bobp))
+				 (preceding-char)))))
+		       (error                                ; found our definition at compile-time.
+			;; load-time check.
+			(condition-case nil
+			    (char-before)
+			  (wrong-number-of-arguments         ; Mule.
+			   (or (fboundp 'si:char-before)
+			       (progn
+				 (fset 'si:char-before (symbol-function 'char-before))
+				 (put 'char-before 'defun-maybe t)
+				 ;; takes IGNORED for backward compatibility.
+				 (defun char-before (&optional pos ignored)
+				   "\
 Return character in current buffer preceding position POS.
 POS is an integer or a buffer pointer.
 If POS is out of range, the value is nil."
-              (si:char-before (or pos (point)))))))
-     (void-function                     ; non-Mule.
-      (defun-maybe char-before (&optional pos)
-        "\
+				   (si:char-before (or pos (point)))))))
+			  (void-function                     ; non-Mule.
+			   (defun-maybe char-before (&optional pos)
+			     "\
 Return character in current buffer preceding position POS.
 POS is an integer or a buffer pointer.
 If POS is out of range, the value is nil."
-        (if pos
-            (save-excursion
-              (and (= (goto-char pos) (point))
-                   (not (bobp))
-                   (preceding-char)))
-          (and (not (bobp))
-               (preceding-char))))))))
+			     (if pos
+				 (save-excursion
+				   (and (= (goto-char pos) (point))
+					(not (bobp))
+					(preceding-char)))
+			       (and (not (bobp))
+				    (preceding-char))))))))
 
 ;; v18, v19: (char-after POS)
 ;; v20: (char-after &optional POS)
 (static-condition-case nil
-    ;; compile-time check.
-    (progn
-      (char-after)
-      (if (get 'char-after 'defun-maybe)
-	  (error "`char-after' is already redefined")))
-  (wrong-number-of-arguments		; v18, v19
-   ;; load-time check.
-   (or (fboundp 'si:char-after)
-       (progn
-         (fset 'si:char-after (symbol-function 'char-after))
-         (put 'char-after 'defun-maybe t)
-         (defun char-after (&optional pos)
-           "\
+		       ;; compile-time check.
+		       (progn
+			 (char-after)
+			 (if (get 'char-after 'defun-maybe)
+			     (error "`char-after' is already redefined")))
+		       (wrong-number-of-arguments		; v18, v19
+			;; load-time check.
+			(or (fboundp 'si:char-after)
+			    (progn
+			      (fset 'si:char-after (symbol-function 'char-after))
+			      (put 'char-after 'defun-maybe t)
+			      (defun char-after (&optional pos)
+				"\
 Return character in current buffer at position POS.
 POS is an integer or a buffer pointer.
 If POS is out of range, the value is nil."
-           (si:char-after (or pos (point)))))))
-  (void-function			; NEVER happen?
-   ;; load-time check.
-   (defun-maybe char-after (&optional pos)
-     "\
+				(si:char-after (or pos (point)))))))
+		       (void-function			; NEVER happen?
+			;; load-time check.
+			(defun-maybe char-after (&optional pos)
+			  "\
 Return character in current buffer at position POS.
 POS is an integer or a buffer pointer.
 If POS is out of range, the value is nil."
-     (if pos
-         (save-excursion
-           (and (= (goto-char pos) (point))
-                (not (eobp))
-                (following-char)))
-       (and (not (eobp))
-            (following-char)))))
-  (error                                ; found our definition at compile-time.
-   ;; load-time check.
-   (condition-case nil
-       (char-after)
-     (wrong-number-of-arguments         ; v18, v19
-      (or (fboundp 'si:char-after)
-          (progn
-            (fset 'si:char-after (symbol-function 'char-after))
-            (put 'char-after 'defun-maybe t)
-	    (defun char-after (&optional pos)
-	      "\
+			  (if pos
+			      (save-excursion
+				(and (= (goto-char pos) (point))
+				     (not (eobp))
+				     (following-char)))
+			    (and (not (eobp))
+				 (following-char)))))
+		       (error                                ; found our definition at compile-time.
+			;; load-time check.
+			(condition-case nil
+			    (char-after)
+			  (wrong-number-of-arguments         ; v18, v19
+			   (or (fboundp 'si:char-after)
+			       (progn
+				 (fset 'si:char-after (symbol-function 'char-after))
+				 (put 'char-after 'defun-maybe t)
+				 (defun char-after (&optional pos)
+				   "\
 Return character in current buffer at position POS.
 POS is an integer or a buffer pointer.
 If POS is out of range, the value is nil."
-	      (si:char-after (or pos (point)))))))
-     (void-function                     ; NEVER happen?
-      (defun-maybe char-after (&optional pos)
-	"\
+				   (si:char-after (or pos (point)))))))
+			  (void-function                     ; NEVER happen?
+			   (defun-maybe char-after (&optional pos)
+			     "\
 Return character in current buffer at position POS.
 POS is an integer or a buffer pointer.
 If POS is out of range, the value is nil."
-	(if pos
-	    (save-excursion
-	      (and (= (goto-char pos) (point))
-		   (not (eobp))
-		   (following-char)))
-	  (and (not (eobp))
-	       (following-char))))))))
+			     (if pos
+				 (save-excursion
+				   (and (= (goto-char pos) (point))
+					(not (eobp))
+					(following-char)))
+			       (and (not (eobp))
+				    (following-char))))))))
 
 ;; Emacs 19.29 and later: (buffer-substring-no-properties START END)
 (defun-maybe buffer-substring-no-properties (start end)
@@ -813,7 +813,7 @@ the value of `foo'."
 ;; So, in Emacs 19.29, `run-hooks' and others will be overrided.
 ;; But, who cares it?
 (static-unless (subrp (symbol-function 'run-hooks))
-  (require 'localhook))
+	       (require 'localhook))
 
 ;; Emacs 19.29/XEmacs 19.14(?) and later: (add-to-list LIST-VAR ELEMENT)
 (defun-maybe add-to-list (list-var element)
@@ -916,20 +916,20 @@ APEL provides this as dummy for compatib
 (defmacro-maybe save-current-buffer (&rest body)
   "Save the current buffer; execute BODY; restore the current buffer.
 Executes BODY just like `progn'."
-  (` (let ((orig-buffer (current-buffer)))
-       (unwind-protect
-	   (progn (,@ body))
-	 (if (buffer-live-p orig-buffer)
-	     (set-buffer orig-buffer))))))
+  `(let ((orig-buffer (current-buffer)))
+     (unwind-protect
+	 (progn ,@body)
+       (if (buffer-live-p orig-buffer)
+	   (set-buffer orig-buffer)))))
 
 ;; Emacs 20.1/XEmacs 20.3(?) and later: (with-current-buffer BUFFER &rest BODY)
 (defmacro-maybe with-current-buffer (buffer &rest body)
   "Execute the forms in BODY with BUFFER as the current buffer.
 The value returned is the value of the last form in BODY.
 See also `with-temp-buffer'."
-  (` (save-current-buffer
-       (set-buffer (, buffer))
-       (,@ body))))
+  `(save-current-buffer
+     (set-buffer ,buffer)
+     ,@body))
 
 ;; Emacs 20.1/XEmacs 20.3(?) and later: (with-temp-file FILE &rest FORMS)
 (defmacro-maybe with-temp-file (file &rest forms)
@@ -938,68 +938,68 @@ The value of the last form in FORMS is r
 See also `with-temp-buffer'."
   (let ((temp-file (make-symbol "temp-file"))
 	(temp-buffer (make-symbol "temp-buffer")))
-    (` (let (((, temp-file) (, file))
-	     ((, temp-buffer)
-	      (get-buffer-create (generate-new-buffer-name " *temp file*"))))
-	 (unwind-protect
-	     (prog1
-		 (with-current-buffer (, temp-buffer)
-		   (,@ forms))
-	       (with-current-buffer (, temp-buffer)
-		 (widen)
-		 (write-region (point-min) (point-max) (, temp-file) nil 0)))
-	   (and (buffer-name (, temp-buffer))
-		(kill-buffer (, temp-buffer))))))))
+    `(let ((,temp-file ,file)
+	   (,temp-buffer
+	    (get-buffer-create (generate-new-buffer-name " *temp file*"))))
+       (unwind-protect
+	   (prog1
+	       (with-current-buffer ,temp-buffer
+		 ,@forms)
+	     (with-current-buffer ,temp-buffer
+	       (widen)
+	       (write-region (point-min) (point-max) ,temp-file nil 0)))
+	 (and (buffer-name ,temp-buffer)
+	      (kill-buffer ,temp-buffer))))))
 
 ;; Emacs 20.4 and later: (with-temp-message MESSAGE &rest BODY)
 ;; This macro uses `current-message', which appears in v20.
 (static-when (and (fboundp 'current-message)
 		  (subrp (symbol-function 'current-message)))
-  (defmacro-maybe with-temp-message (message &rest body)
-    "\
+	     (defmacro-maybe with-temp-message (message &rest body)
+	       "\
 Display MESSAGE temporarily if non-nil while BODY is evaluated.
 The original message is restored to the echo area after BODY has finished.
 The value returned is the value of the last form in BODY.
 MESSAGE is written to the message log buffer if `message-log-max' is non-nil.
 If MESSAGE is nil, the echo area and message log buffer are unchanged.
 Use a MESSAGE of \"\" to temporarily clear the echo area."
-    (let ((current-message (make-symbol "current-message"))
-	  (temp-message (make-symbol "with-temp-message")))
-      (` (let (((, temp-message) (, message))
-	       ((, current-message)))
-	   (unwind-protect
-	       (progn
-		 (when (, temp-message)
-		   (setq (, current-message) (current-message))
-		   (message "%s" (, temp-message))
-		   (,@ body))
-		 (and (, temp-message) (, current-message)
-		      (message "%s" (, current-message))))))))))
+	       (let ((current-message (make-symbol "current-message"))
+		     (temp-message (make-symbol "with-temp-message")))
+		 `(let ((,temp-message ,message)
+			(,current-message))
+		    (unwind-protect
+			(progn
+			  (when ,temp-message
+			    (setq ,current-message (current-message))
+			    (message "%s" ,temp-message)
+			    ,@body)
+			  (and ,temp-message ,current-message
+			       (message "%s" ,current-message))))))))
 
 ;; Emacs 20.1/XEmacs 20.3(?) and later: (with-temp-buffer &rest FORMS)
 (defmacro-maybe with-temp-buffer (&rest forms)
   "Create a temporary buffer, and evaluate FORMS there like `progn'.
 See also `with-temp-file' and `with-output-to-string'."
   (let ((temp-buffer (make-symbol "temp-buffer")))
-    (` (let (((, temp-buffer)
-	      (get-buffer-create (generate-new-buffer-name " *temp*"))))
-	 (unwind-protect
-	     (with-current-buffer (, temp-buffer)
-	       (,@ forms))
-	   (and (buffer-name (, temp-buffer))
-		(kill-buffer (, temp-buffer))))))))
+    `(let ((,temp-buffer
+	    (get-buffer-create (generate-new-buffer-name " *temp*"))))
+       (unwind-protect
+	   (with-current-buffer ,temp-buffer
+	     ,@forms)
+	 (and (buffer-name ,temp-buffer)
+	      (kill-buffer ,temp-buffer))))))
 
 ;; Emacs 20.1/XEmacs 20.3(?) and later: (with-output-to-string &rest BODY)
 (defmacro-maybe with-output-to-string (&rest body)
   "Execute BODY, return the text it sent to `standard-output', as a string."
-  (` (let ((standard-output
-	    (get-buffer-create (generate-new-buffer-name " *string-output*"))))
-       (let ((standard-output standard-output))
-	 (,@ body))
-       (with-current-buffer standard-output
-	 (prog1
-	     (buffer-string)
-	   (kill-buffer nil))))))
+  `(let ((standard-output
+	  (get-buffer-create (generate-new-buffer-name " *string-output*"))))
+     (let ((standard-output standard-output))
+       ,@body)
+     (with-current-buffer standard-output
+       (prog1
+	   (buffer-string)
+	 (kill-buffer nil)))))

 ;; Emacs 20.1 and later: (combine-after-change-calls &rest BODY)
 (defmacro-maybe combine-after-change-calls (&rest body)
@@ -1056,20 +1056,20 @@ STRING should be given if the last searc
 ;; We support following API.
 ;;  (replace-match NEWTEXT &optional FIXEDCASE LITERAL STRING)
 (static-condition-case nil
-    ;; compile-time check
-    (progn
-      (string-match "" "")
-      (replace-match "" nil nil "")
-      (if (get 'replace-match 'defun-maybe)
-	  (error "`replace-match' is already defined")))
-  (wrong-number-of-arguments ; Emacs 19.28 and earlier
-   ;; load-time check.
-   (or (fboundp 'si:replace-match)
-       (progn
-	 (fset 'si:replace-match (symbol-function 'replace-match))
-	 (put 'replace-match 'defun-maybe t)
-	 (defun replace-match (newtext &optional fixedcase literal string)
-	   "Replace text matched by last search with NEWTEXT.
+		       ;; compile-time check
+		       (progn
+			 (string-match "" "")
+			 (replace-match "" nil nil "")
+			 (if (get 'replace-match 'defun-maybe)
+			     (error "`replace-match' is already defined")))
+		       (wrong-number-of-arguments ; Emacs 19.28 and earlier
+			;; load-time check.
+			(or (fboundp 'si:replace-match)
+			    (progn
+			      (fset 'si:replace-match (symbol-function 'replace-match))
+			      (put 'replace-match 'defun-maybe t)
+			      (defun replace-match (newtext &optional fixedcase literal string)
+				"Replace text matched by last search with NEWTEXT.
 If second arg FIXEDCASE is non-nil, do not alter case of replacement text.
 Otherwise maybe capitalize the whole text, or maybe just word initials,
 based on the replaced text.
@@ -1080,48 +1080,48 @@ then capitalize each word in NEWTEXT.

 If third arg LITERAL is non-nil, insert NEWTEXT literally.
 Otherwise treat `\' as special:
-  `\&' in NEWTEXT means substitute original matched text.
-  `\N' means substitute what matched the Nth `\(...\)'.
+  `\\&' in NEWTEXT means substitute original matched text.
+  `\\N' means substitute what matched the Nth `\\(...\\)'.
        If Nth parens didn't match, substitute nothing.
-  `\\' means insert one `\'.
+  `\\\\' means insert one `\\'.
 FIXEDCASE and LITERAL are optional arguments.
 Leaves point at end of replacement text.

 The optional fourth argument STRING can be a string to modify.
 In that case, this function creates and returns a new string
 which is made by replacing the part of STRING that was matched."
-	   (if string
-	       (with-temp-buffer
-		(save-match-data
-		  (insert string)
-		  (let* ((matched (match-data))
-			 (beg (nth 0 matched))
-			 (end (nth 1 matched)))
-		    (store-match-data
-		     (list
-		      (if (markerp beg)
-			  (move-marker beg (1+ (match-beginning 0)))
-			(1+ (match-beginning 0)))
-		      (if (markerp end)
-			  (move-marker end (1+ (match-end 0)))
-			(1+ (match-end 0))))))
-		  (si:replace-match newtext fixedcase literal)
-		  (buffer-string)))
-	     (si:replace-match newtext fixedcase literal))))))
-  (error ; found our definition at compile-time.
-   ;; load-time check.
-   (condition-case nil
-    (progn
-      (string-match "" "")
-      (replace-match "" nil nil ""))
-    (wrong-number-of-arguments ; Emacs 19.28 and earlier
-     ;; load-time check.
-     (or (fboundp 'si:replace-match)
-	 (progn
-	   (fset 'si:replace-match (symbol-function 'replace-match))
-	   (put 'replace-match 'defun-maybe t)
-	   (defun replace-match (newtext &optional fixedcase literal string)
-	     "Replace text matched by last search with NEWTEXT.
+				(if string
+				    (with-temp-buffer
+				      (save-match-data
+					(insert string)
+					(let* ((matched (match-data))
+					       (beg (nth 0 matched))
+					       (end (nth 1 matched)))
+					  (store-match-data
+					   (list
+					    (if (markerp beg)
+						(move-marker beg (1+ (match-beginning 0)))
+					      (1+ (match-beginning 0)))
+					    (if (markerp end)
+						(move-marker end (1+ (match-end 0)))
+					      (1+ (match-end 0))))))
+					(si:replace-match newtext fixedcase literal)
+					(buffer-string)))
+				  (si:replace-match newtext fixedcase literal))))))
+		       (error ; found our definition at compile-time.
+			;; load-time check.
+			(condition-case nil
+			    (progn
+			      (string-match "" "")
+			      (replace-match "" nil nil ""))
+			  (wrong-number-of-arguments ; Emacs 19.28 and earlier
+			   ;; load-time check.
+			   (or (fboundp 'si:replace-match)
+			       (progn
+				 (fset 'si:replace-match (symbol-function 'replace-match))
+				 (put 'replace-match 'defun-maybe t)
+				 (defun replace-match (newtext &optional fixedcase literal string)
+				   "Replace text matched by last search with NEWTEXT.
 If second arg FIXEDCASE is non-nil, do not alter case of replacement text.
 Otherwise maybe capitalize the whole text, or maybe just word initials,
 based on the replaced text.
@@ -1132,34 +1132,34 @@ then capitalize each word in NEWTEXT.

 If third arg LITERAL is non-nil, insert NEWTEXT literally.
 Otherwise treat `\' as special:
-  `\&' in NEWTEXT means substitute original matched text.
-  `\N' means substitute what matched the Nth `\(...\)'.
+  `\\&' in NEWTEXT means substitute original matched text.
+  `\\N' means substitute what matched the Nth `\\(...\\)'.
        If Nth parens didn't match, substitute nothing.
-  `\\' means insert one `\'.
+  `\\\\' means insert one `\'.
 FIXEDCASE and LITERAL are optional arguments.
 Leaves point at end of replacement text.

 The optional fourth argument STRING can be a string to modify.
 In that case, this function creates and returns a new string
 which is made by replacing the part of STRING that was matched."
-	     (if string
-		 (with-temp-buffer
-		  (save-match-data
-		    (insert string)
-		    (let* ((matched (match-data))
-			   (beg (nth 0 matched))
-			   (end (nth 1 matched)))
-		      (store-match-data
-		       (list
-			(if (markerp beg)
-			    (move-marker beg (1+ (match-beginning 0)))
-			  (1+ (match-beginning 0)))
-			(if (markerp end)
-			    (move-marker end (1+ (match-end 0)))
-			  (1+ (match-end 0))))))
-		    (si:replace-match newtext fixedcase literal)
-		    (buffer-string)))
-	       (si:replace-match newtext fixedcase literal)))))))))
+				   (if string
+				       (with-temp-buffer
+					 (save-match-data
+					   (insert string)
+					   (let* ((matched (match-data))
+						  (beg (nth 0 matched))
+						  (end (nth 1 matched)))
+					     (store-match-data
+					      (list
+					       (if (markerp beg)
+						   (move-marker beg (1+ (match-beginning 0)))
+						 (1+ (match-beginning 0)))
+					       (if (markerp end)
+						   (move-marker end (1+ (match-end 0)))
+						 (1+ (match-end 0))))))
+					   (si:replace-match newtext fixedcase literal)
+					   (buffer-string)))
+				     (si:replace-match newtext fixedcase literal)))))))))
 
 ;; Emacs 20: (format-time-string FORMAT &optional TIME UNIVERSAL)
 ;; Those format constructs are yet to be implemented.
@@ -1167,26 +1167,26 @@ which is made by replacing the part of S
 ;; Not fully compatible especially when invalid format is specified.
 (static-unless (and (fboundp 'format-time-string)
 		    (not (get 'format-time-string 'defun-maybe)))
-  (or (fboundp 'format-time-string)
-  (progn
-  (defconst format-time-month-list
-    '(( "Zero" . ("Zero" . 0))
-      ("Jan" . ("January" . 1)) ("Feb" . ("February" . 2))
-      ("Mar" . ("March" . 3)) ("Apr" . ("April" . 4)) ("May" . ("May" . 5))
-      ("Jun" . ("June" . 6))("Jul" . ("July" . 7)) ("Aug" . ("August" . 8))
-      ("Sep" . ("September" . 9)) ("Oct" . ("October" . 10))
-      ("Nov" . ("November" . 11)) ("Dec" . ("December" . 12)))
-    "Alist of months and their number.")
+	       (or (fboundp 'format-time-string)
+		   (progn
+		     (defconst format-time-month-list
+		       '(( "Zero" . ("Zero" . 0))
+			 ("Jan" . ("January" . 1)) ("Feb" . ("February" . 2))
+			 ("Mar" . ("March" . 3)) ("Apr" . ("April" . 4)) ("May" . ("May" . 5))
+			 ("Jun" . ("June" . 6))("Jul" . ("July" . 7)) ("Aug" . ("August" . 8))
+			 ("Sep" . ("September" . 9)) ("Oct" . ("October" . 10))
+			 ("Nov" . ("November" . 11)) ("Dec" . ("December" . 12)))
+		       "Alist of months and their number.")
 
-  (defconst format-time-week-list
-    '(("Sun" . ("Sunday" . 0)) ("Mon" . ("Monday" . 1))
-      ("Tue" . ("Tuesday" . 2)) ("Wed" . ("Wednesday" . 3))
-      ("Thu" . ("Thursday" . 4)) ("Fri" . ("Friday" . 5))
-      ("Sat" . ("Saturday" . 6)))
-    "Alist of weeks and their number.")
+		     (defconst format-time-week-list
+		       '(("Sun" . ("Sunday" . 0)) ("Mon" . ("Monday" . 1))
+			 ("Tue" . ("Tuesday" . 2)) ("Wed" . ("Wednesday" . 3))
+			 ("Thu" . ("Thursday" . 4)) ("Fri" . ("Friday" . 5))
+			 ("Sat" . ("Saturday" . 6)))
+		       "Alist of weeks and their number.")
 
-  (defun format-time-string (format &optional time universal)
-    "Use FORMAT-STRING to format the time TIME, or now if omitted.
+		     (defun format-time-string (format &optional time universal)
+		       "Use FORMAT-STRING to format the time TIME, or now if omitted.
 TIME is specified as (HIGH LOW . IGNORED) or (HIGH . LOW), as returned by
 `current-time' or `file-attributes'.
 The third, optional, argument UNIVERSAL, if non-nil, means describe TIME
@@ -1238,250 +1238,250 @@ Compatibility Note.
 Those format constructs are yet to be implemented.
   %c, %C, %j, %U, %W, %x, %X
 Not fully compatible especially when invalid format is specified."
-    (let ((fmt-len (length format))
-	  (ind 0)
-	  prev-ind
-	  cur-char
-	  (prev-char nil)
-	  strings-so-far
-	  (result "")
-	  field-width
-	  field-result
-	  pad-left change-case
-	  (paren-level 0)
-	  hour ms ls
-	  (tz (car (current-time-zone)))
-	  time-string)
-      (if universal
-	  (progn
-	    (or time
-		(setq time (current-time)))
-	    (setq ms (car time)
-		  ls (- (nth 1 time) tz))
-	    (cond ((< ls 0)
-		   (setq ms (1- ms)
-			 ls (+ ls 65536)))
-		  ((>= ls 65536)
-		   (setq ms (1+ ms)
-			 ls (- ls 65536))))
-	    (setq time (append (list ms ls) (nth 2 time)))))
-      (setq time-string (current-time-string time)
-	    hour (string-to-int (substring time-string 11 13)))
-      (while (< ind fmt-len)
-	(setq cur-char (aref format ind))
-	(setq
-	 result
-	 (concat result
-	(cond
-	 ((eq cur-char ?%)
-	  ;; eat any additional args to allow for future expansion, not!!
-	  (setq pad-left nil change-case nil field-width "" prev-ind ind
-		strings-so-far "")
-;	  (catch 'invalid
-	  (while (progn
-		   (setq ind (1+ ind))
-		   (setq cur-char (if (< ind fmt-len)
-				      (aref format ind)
-				    ?\0))
-		   (or (eq ?- cur-char) ; pad on left
-		       (eq ?# cur-char) ; case change
-		       (if (and (string-equal field-width "")
-				(<= ?0 cur-char) (>= ?9 cur-char))
-			   ;; get format width
-			   (let ((field-index ind))
-			     (while (progn
-				      (setq ind (1+ ind))
-				      (setq cur-char (if (< ind fmt-len)
-							 (aref format ind)
-						       ?\0))
-				      (and (<= ?0 cur-char) (>= ?9 cur-char))))
-			     (setq field-width
-				   (substring format field-index ind))
-			     (setq ind (1- ind)
-				   cur-char nil)
-			     t))))
-	    (setq prev-char cur-char
-		  strings-so-far (concat strings-so-far
-					 (if cur-char
-					     (char-to-string cur-char)
-					   field-width)))
-	    ;; characters we actually use
-	    (cond ((eq cur-char ?-)
-		   ;; padding to left must be specified before field-width
-		   (setq pad-left (string-equal field-width "")))
-		  ((eq cur-char ?#)
-		   (setq change-case t))))
-	  (setq field-result
-		(cond
-		 ((eq cur-char ?%)
-		  "%")
-		 ;; the abbreviated name of the day of week.
-		 ((eq cur-char ?a)
-		  (substring time-string 0 3))
-		 ;; the full name of the day of week
-		 ((eq cur-char ?A)
-		  (cadr (assoc (substring time-string 0 3)
-			       format-time-week-list)))
-		 ;; the abbreviated name of the month
-		 ((eq cur-char ?b)
-		  (substring time-string 4 7))
-		 ;; the full name of the month
-		 ((eq cur-char ?B)
-		  (cadr (assoc (substring time-string 4 7)
-			       format-time-month-list)))
-		 ;; a synonym for `%x %X' (yet to come)
-		 ((eq cur-char ?c)
-		  "")
-		 ;; locale specific (yet to come)
-		 ((eq cur-char ?C)
-		  "")
-		 ;; the day of month, zero-padded
-		 ((eq cur-char ?d)
-		  (format "%02d" (string-to-int (substring time-string 8 10))))
-		 ;; a synonym for `%m/%d/%y'
-		 ((eq cur-char ?D)
-		  (format "%02d/%02d/%s"
-			  (cddr (assoc (substring time-string 4 7)
-				       format-time-month-list))
-			  (string-to-int (substring time-string 8 10))
-			  (substring time-string -2)))
-		 ;; the day of month, blank-padded
-		 ((eq cur-char ?e)
-		  (format "%2d" (string-to-int (substring time-string 8 10))))
-		 ;; a synonym for `%b'
-		 ((eq cur-char ?h)
-		  (substring time-string 4 7))
-		 ;; the hour (00-23)
-		 ((eq cur-char ?H)
-		  (substring time-string 11 13))
-		 ;; the hour (00-12)
-		 ((eq cur-char ?I)
-		  (format "%02d" (if (> hour 12) (- hour 12) hour)))
-		 ;; the day of the year (001-366) (yet to come)
-		 ((eq cur-char ?j)
-		  "")
-		 ;; the hour (0-23), blank padded
-		 ((eq cur-char ?k)
-		  (format "%2d" hour))
-		 ;; the hour (1-12), blank padded
-		 ((eq cur-char ?l)
-		  (format "%2d" (if (> hour 12) (- hour 12) hour)))
-		 ;; the month (01-12)
-		 ((eq cur-char ?m)
-		  (format "%02d" (cddr (assoc (substring time-string 4 7)
-					      format-time-month-list))))
-		 ;; the minute (00-59)
-		 ((eq cur-char ?M)
-		  (substring time-string 14 16))
-		 ;; a newline
-		 ((eq cur-char ?n)
-		  "\n")
-		 ;; `AM' or `PM', as appropriate
-		 ((eq cur-char ?p)
-		  (setq change-case (not change-case))
-		  (if (> hour 12) "pm" "am"))
-		 ;; a synonym for `%I:%M:%S %p'
-		 ((eq cur-char ?r)
-		  (format "%02d:%s:%s %s"
-			  (if (> hour 12) (- hour 12) hour)
-			  (substring time-string 14 16)
-			  (substring time-string 17 19)
-			  (if (> hour 12) "PM" "AM")))
-		 ;; a synonym for `%H:%M'
-		 ((eq cur-char ?R)
-		  (format "%s:%s"
-			  (substring time-string 11 13)
-			  (substring time-string 14 16)))
-		 ;; the seconds (00-60)
-		 ((eq cur-char ?S)
-		  (substring time-string 17 19))
-		 ;; a tab character
-		 ((eq cur-char ?t)
-		  "\t")
-		 ;; a synonym for `%H:%M:%S'
-		 ((eq cur-char ?T)
-		  (format "%s:%s:%s"
-			  (substring time-string 11 13)
-			  (substring time-string 14 16)
-			  (substring time-string 17 19)))
-		 ;; the week of the year (01-52), assuming that weeks
-		 ;; start on Sunday (yet to come)
-		 ((eq cur-char ?U)
-		  "")
-		 ;; the numeric day of week (0-6).  Sunday is day 0
-		 ((eq cur-char ?w)
-		  (format "%d" (cddr (assoc (substring time-string 0 3)
-					    format-time-week-list))))
-		 ;; the week of the year (01-52), assuming that weeks
-		 ;; start on Monday (yet to come)
-		 ((eq cur-char ?W)
-		  "")
-		 ;; locale specific (yet to come)
-		 ((eq cur-char ?x)
-		  "")
-		 ;; locale specific (yet to come)
-		 ((eq cur-char ?X)
-		  "")
-		 ;; the year without century (00-99)
-		 ((eq cur-char ?y)
-		  (substring time-string -2))
-		 ;; the year with century
-		 ((eq cur-char ?Y)
-		  (substring time-string -4))
-		 ;; the time zone abbreviation
-		 ((eq cur-char ?Z)
-		  (if universal
-		      "UTC"
-		    (setq change-case (not change-case))
-		    (downcase (cadr (current-time-zone)))))
-		 ((eq cur-char ?z)
-		  (if universal
-		      "+0000"
-		    (if (< tz 0)
-			(format "-%02d%02d"
-				(/ (- tz) 3600) (/ (% (- tz) 3600) 60))
-		      (format "+%02d%02d"
-			      (/ tz 3600) (/ (% tz 3600) 60)))))
-		 (t
-		  (concat
-		   "%"
-		   strings-so-far
-		   (char-to-string cur-char)))))
-;		  (setq ind prev-ind)
-;		  (throw 'invalid "%"))))
-	  (if (string-equal field-width "")
-	      (if change-case (upcase field-result) field-result)
-	    (let ((padded-result
-		   (format (format "%%%s%s%c"
-				   ""	; pad on left is ignored
-;				   (if pad-left "-" "")
-				   field-width
-				   ?s)
-			   (or field-result ""))))
-	      (let ((initial-length (length padded-result))
-		    (desired-length (string-to-int field-width)))
-		(when (and (string-match "^0" field-width)
-			   (string-match "^ +" padded-result))
-		  (setq padded-result
-			(replace-match
-			 (make-string
-			  (length (match-string 0 padded-result)) ?0)
-			 nil nil padded-result)))
-		(if (> initial-length desired-length)
-		    ;; truncate strings on right, years on left
-		    (if (stringp field-result)
-			(substring padded-result 0 desired-length)
-		      (if (eq cur-char ?y)
-			  (substring padded-result (- desired-length))
-			padded-result))) ;non-year numbers don't truncate
-		(if change-case (upcase padded-result) padded-result))))) ;)
-	 (t
-	  (char-to-string cur-char)))))
-	(setq ind (1+ ind)))
-      result))
-  ;; for `load-history'.
-  (setq current-load-list (cons 'format-time-string current-load-list))
-  (put 'format-time-string 'defun-maybe t))))
+		       (let ((fmt-len (length format))
+			     (ind 0)
+			     prev-ind
+			     cur-char
+			     (prev-char nil)
+			     strings-so-far
+			     (result "")
+			     field-width
+			     field-result
+			     pad-left change-case
+			     (paren-level 0)
+			     hour ms ls
+			     (tz (car (current-time-zone)))
+			     time-string)
+			 (if universal
+			     (progn
+			       (or time
+				   (setq time (current-time)))
+			       (setq ms (car time)
+				     ls (- (nth 1 time) tz))
+			       (cond ((< ls 0)
+				      (setq ms (1- ms)
+					    ls (+ ls 65536)))
+				     ((>= ls 65536)
+				      (setq ms (1+ ms)
+					    ls (- ls 65536))))
+			       (setq time (append (list ms ls) (nth 2 time)))))
+			 (setq time-string (current-time-string time)
+			       hour (string-to-int (substring time-string 11 13)))
+			 (while (< ind fmt-len)
+			   (setq cur-char (aref format ind))
+			   (setq
+			    result
+			    (concat result
+				    (cond
+				     ((eq cur-char ?%)
+				      ;; eat any additional args to allow for future expansion, not!!
+				      (setq pad-left nil change-case nil field-width "" prev-ind ind
+					    strings-so-far "")
+					;	  (catch 'invalid
+				      (while (progn
+					       (setq ind (1+ ind))
+					       (setq cur-char (if (< ind fmt-len)
+								  (aref format ind)
+								?\0))
+					       (or (eq ?- cur-char) ; pad on left
+						   (eq ?# cur-char) ; case change
+						   (if (and (string-equal field-width "")
+							    (<= ?0 cur-char) (>= ?9 cur-char))
+						       ;; get format width
+						       (let ((field-index ind))
+							 (while (progn
+								  (setq ind (1+ ind))
+								  (setq cur-char (if (< ind fmt-len)
+										     (aref format ind)
+										   ?\0))
+								  (and (<= ?0 cur-char) (>= ?9 cur-char))))
+							 (setq field-width
+							       (substring format field-index ind))
+							 (setq ind (1- ind)
+							       cur-char nil)
+							 t))))
+					(setq prev-char cur-char
+					      strings-so-far (concat strings-so-far
+								     (if cur-char
+									 (char-to-string cur-char)
+								       field-width)))
+					;; characters we actually use
+					(cond ((eq cur-char ?-)
+					       ;; padding to left must be specified before field-width
+					       (setq pad-left (string-equal field-width "")))
+					      ((eq cur-char ?#)
+					       (setq change-case t))))
+				      (setq field-result
+					    (cond
+					     ((eq cur-char ?%)
+					      "%")
+					     ;; the abbreviated name of the day of week.
+					     ((eq cur-char ?a)
+					      (substring time-string 0 3))
+					     ;; the full name of the day of week
+					     ((eq cur-char ?A)
+					      (cadr (assoc (substring time-string 0 3)
+							   format-time-week-list)))
+					     ;; the abbreviated name of the month
+					     ((eq cur-char ?b)
+					      (substring time-string 4 7))
+					     ;; the full name of the month
+					     ((eq cur-char ?B)
+					      (cadr (assoc (substring time-string 4 7)
+							   format-time-month-list)))
+					     ;; a synonym for `%x %X' (yet to come)
+					     ((eq cur-char ?c)
+					      "")
+					     ;; locale specific (yet to come)
+					     ((eq cur-char ?C)
+					      "")
+					     ;; the day of month, zero-padded
+					     ((eq cur-char ?d)
+					      (format "%02d" (string-to-int (substring time-string 8 10))))
+					     ;; a synonym for `%m/%d/%y'
+					     ((eq cur-char ?D)
+					      (format "%02d/%02d/%s"
+						      (cddr (assoc (substring time-string 4 7)
+								   format-time-month-list))
+						      (string-to-int (substring time-string 8 10))
+						      (substring time-string -2)))
+					     ;; the day of month, blank-padded
+					     ((eq cur-char ?e)
+					      (format "%2d" (string-to-int (substring time-string 8 10))))
+					     ;; a synonym for `%b'
+					     ((eq cur-char ?h)
+					      (substring time-string 4 7))
+					     ;; the hour (00-23)
+					     ((eq cur-char ?H)
+					      (substring time-string 11 13))
+					     ;; the hour (00-12)
+					     ((eq cur-char ?I)
+					      (format "%02d" (if (> hour 12) (- hour 12) hour)))
+					     ;; the day of the year (001-366) (yet to come)
+					     ((eq cur-char ?j)
+					      "")
+					     ;; the hour (0-23), blank padded
+					     ((eq cur-char ?k)
+					      (format "%2d" hour))
+					     ;; the hour (1-12), blank padded
+					     ((eq cur-char ?l)
+					      (format "%2d" (if (> hour 12) (- hour 12) hour)))
+					     ;; the month (01-12)
+					     ((eq cur-char ?m)
+					      (format "%02d" (cddr (assoc (substring time-string 4 7)
+									  format-time-month-list))))
+					     ;; the minute (00-59)
+					     ((eq cur-char ?M)
+					      (substring time-string 14 16))
+					     ;; a newline
+					     ((eq cur-char ?n)
+					      "\n")
+					     ;; `AM' or `PM', as appropriate
+					     ((eq cur-char ?p)
+					      (setq change-case (not change-case))
+					      (if (> hour 12) "pm" "am"))
+					     ;; a synonym for `%I:%M:%S %p'
+					     ((eq cur-char ?r)
+					      (format "%02d:%s:%s %s"
+						      (if (> hour 12) (- hour 12) hour)
+						      (substring time-string 14 16)
+						      (substring time-string 17 19)
+						      (if (> hour 12) "PM" "AM")))
+					     ;; a synonym for `%H:%M'
+					     ((eq cur-char ?R)
+					      (format "%s:%s"
+						      (substring time-string 11 13)
+						      (substring time-string 14 16)))
+					     ;; the seconds (00-60)
+					     ((eq cur-char ?S)
+					      (substring time-string 17 19))
+					     ;; a tab character
+					     ((eq cur-char ?t)
+					      "\t")
+					     ;; a synonym for `%H:%M:%S'
+					     ((eq cur-char ?T)
+					      (format "%s:%s:%s"
+						      (substring time-string 11 13)
+						      (substring time-string 14 16)
+						      (substring time-string 17 19)))
+					     ;; the week of the year (01-52), assuming that weeks
+					     ;; start on Sunday (yet to come)
+					     ((eq cur-char ?U)
+					      "")
+					     ;; the numeric day of week (0-6).  Sunday is day 0
+					     ((eq cur-char ?w)
+					      (format "%d" (cddr (assoc (substring time-string 0 3)
+									format-time-week-list))))
+					     ;; the week of the year (01-52), assuming that weeks
+					     ;; start on Monday (yet to come)
+					     ((eq cur-char ?W)
+					      "")
+					     ;; locale specific (yet to come)
+					     ((eq cur-char ?x)
+					      "")
+					     ;; locale specific (yet to come)
+					     ((eq cur-char ?X)
+					      "")
+					     ;; the year without century (00-99)
+					     ((eq cur-char ?y)
+					      (substring time-string -2))
+					     ;; the year with century
+					     ((eq cur-char ?Y)
+					      (substring time-string -4))
+					     ;; the time zone abbreviation
+					     ((eq cur-char ?Z)
+					      (if universal
+						  "UTC"
+						(setq change-case (not change-case))
+						(downcase (cadr (current-time-zone)))))
+					     ((eq cur-char ?z)
+					      (if universal
+						  "+0000"
+						(if (< tz 0)
+						    (format "-%02d%02d"
+							    (/ (- tz) 3600) (/ (% (- tz) 3600) 60))
+						  (format "+%02d%02d"
+							  (/ tz 3600) (/ (% tz 3600) 60)))))
+					     (t
+					      (concat
+					       "%"
+					       strings-so-far
+					       (char-to-string cur-char)))))
+					;		  (setq ind prev-ind)
+					;		  (throw 'invalid "%"))))
+				      (if (string-equal field-width "")
+					  (if change-case (upcase field-result) field-result)
+					(let ((padded-result
+					       (format (format "%%%s%s%c"
+							       ""	; pad on left is ignored
+					;				   (if pad-left "-" "")
+							       field-width
+							       ?s)
+						       (or field-result ""))))
+					  (let ((initial-length (length padded-result))
+						(desired-length (string-to-int field-width)))
+					    (when (and (string-match "^0" field-width)
+						       (string-match "^ +" padded-result))
+					      (setq padded-result
+						    (replace-match
+						     (make-string
+						      (length (match-string 0 padded-result)) ?0)
+						     nil nil padded-result)))
+					    (if (> initial-length desired-length)
+						;; truncate strings on right, years on left
+						(if (stringp field-result)
+						    (substring padded-result 0 desired-length)
+						  (if (eq cur-char ?y)
+						      (substring padded-result (- desired-length))
+						    padded-result))) ;non-year numbers don't truncate
+					    (if change-case (upcase padded-result) padded-result))))) ;)
+				     (t
+				      (char-to-string cur-char)))))
+			   (setq ind (1+ ind)))
+			 result))
+		     ;; for `load-history'.
+		     (setq current-load-list (cons 'format-time-string current-load-list))
+		     (put 'format-time-string 'defun-maybe t))))
 
 ;; Emacs 19.29-19.34/XEmacs: `format-time-string' neither supports the
 ;; format string "%z" nor the third argument `universal'.
@@ -1667,7 +1667,7 @@ See `walk-windows' for the meaning of MI
                      )))
       ;; arglist: (prefix &optional dir-flag suffix)
       (cond
-       ((not arglist)
+       ((or (not arglist) (not (listp arglist)))
         ;; `make-temp-file' is a built-in; expects 3-args.
         (put 'make-temp-file 'defun-maybe '3-args))
        ((> (length arglist) 3)
