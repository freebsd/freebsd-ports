Index: eword-encode.el
===================================================================
--- eword-encode.el	(revision 2)
+++ eword-encode.el	(working copy)
@@ -162,15 +162,15 @@
 ;;;
 
 (defmacro make-ew-rword (text charset encoding type)
-  (` (list (, text)(, charset)(, encoding)(, type))))
+  `(list ,text ,charset ,encoding ,type))
 (defmacro ew-rword-text (rword)
-  (` (car (, rword))))
+  `(car ,rword))
 (defmacro ew-rword-charset (rword)
-  (` (car (cdr (, rword)))))
+  `(car (cdr ,rword)))
 (defmacro ew-rword-encoding (rword)
-  (` (car (cdr (cdr (, rword))))))
+  `(car (cdr (cdr ,rword))))
 (defmacro ew-rword-type (rword)
-  (` (car (cdr (cdr (cdr (, rword)))))))
+  `(car (cdr (cdr (cdr ,rword)))))
 
 (defun ew-find-charset-rule (charsets)
   (if charsets
@@ -184,31 +184,31 @@
 ;; which is not depended on the Mule model.  We should redesign
 ;; `eword-encode-split-string' to avoid to depend on the Mule model.
 (if (featurep 'utf-2000)
-;; for CHISE Architecture
-(defun tm-eword::words-to-ruled-words (wl &optional mode)
-  (let (mcs)
+    ;; for CHISE Architecture
+    (defun tm-eword::words-to-ruled-words (wl &optional mode)
+      (let (mcs)
+	(mapcar (function
+		 (lambda (word)
+		   (setq mcs (detect-mime-charset-string (cdr word)))
+		   (make-ew-rword
+		    (cdr word)
+		    mcs
+		    (cdr (or (assq mcs mime-header-charset-encoding-alist)
+			     (cons mcs mime-header-default-charset-encoding)))
+		    mode)
+		   ))
+		wl)))
+
+  ;; for legacy Mule
+  (defun tm-eword::words-to-ruled-words (wl &optional mode)
     (mapcar (function
 	     (lambda (word)
-	       (setq mcs (detect-mime-charset-string (cdr word)))
-	       (make-ew-rword
-		(cdr word)
-		mcs
-		(cdr (or (assq mcs mime-header-charset-encoding-alist)
-			 (cons mcs mime-header-default-charset-encoding)))
-		mode)
-	       ))
-	    wl)))
+	       (let ((ret (ew-find-charset-rule (car word))))
+		 (make-ew-rword (cdr word) (car ret)(nth 1 ret) mode)
+		 )))
+	    wl))
+  )
 
-;; for legacy Mule
-(defun tm-eword::words-to-ruled-words (wl &optional mode)
-  (mapcar (function
-	   (lambda (word)
-	     (let ((ret (ew-find-charset-rule (car word))))
-	       (make-ew-rword (cdr word) (car ret)(nth 1 ret) mode)
-	       )))
-	  wl))
-)
-
 (defun ew-space-process (seq)
   (let (prev a ac b c cc)
     (while seq
