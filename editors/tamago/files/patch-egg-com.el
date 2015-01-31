--- egg-com.el.orig	2015-01-31 19:24:09.000000000 +0900
+++ egg-com.el	2015-01-31 19:25:52.000000000 +0900
@@ -99,9 +99,10 @@
     (prog1 (- (point) pos)
       (goto-char pos))))
 
-(eval-and-compile
-  (if (string< mule-version "6.0") ;; for before Emacs23
-      (progn
+(if (and (fboundp 'make-coding-system)
+         (null (get 'make-coding-system 'byte-obsolete-info)))
+;; since Emacs 23.1, make-coding-system has been marked as obsolete. 
+    (eval-and-compile
 	(define-ccl-program ccl-decode-fixed-euc-jp
 	  `(2
 	    ((r2 = ,(charset-id 'japanese-jisx0208))
@@ -156,7 +157,8 @@
 	(make-coding-system 'fixed-euc-jp 4 ?W "Coding System for fixed EUC Japanese"
 			    (cons ccl-decode-fixed-euc-jp ccl-encode-fixed-euc-jp))
 	)
-    ;; Emacs23 or later
+    (eval-and-compile
+    ;; since Emacs 23.1, make-coding-system has been marked as obsolete. 
     ;; From Handa-san. [mule-ja : No.09414]
     (define-charset 'fixed-euc-jp
       "Fixed EUC Japanese"
@@ -175,7 +177,10 @@
 
 ;; Korean
 
-(eval-and-compile
+(if (and (fboundp 'make-coding-system)
+         (null (get 'make-coding-system 'byte-obsolete-info)))
+;; since Emacs 23.1, make-coding-system has been marked as obsolete. 
+    (eval-and-compile
 (define-ccl-program ccl-decode-fixed-euc-kr
   `(2
     ((r2 = ,(charset-id 'korean-ksc5601))
@@ -202,12 +207,27 @@
 	   (write-read-repeat r0)))
       (read r0)
       (repeat)))))
+(make-coding-system 'fixed-euc-kr 4 ?W "Coding System for fixed EUC Korean"
+		    (cons ccl-decode-fixed-euc-kr ccl-encode-fixed-euc-kr)))
+    (eval-and-compile
+    ;; since Emacs 23.1, make-coding-system has been marked as obsolete. 
+    (define-charset 'fixed-euc-kr
+      "Fixed EUC Korean"
+      :dimension 2
+      :superset '(ascii
+		  (korean-ksc5601 . #x8080)))
+    (define-coding-system 'fixed-euc-kr
+      "Coding System for fixed EUC Korean"
+      :mnemonic ?W
+      :coding-type 'charset
+      :charset-list '(fixed-euc-kr))
+    )
 )
 
-(make-coding-system 'fixed-euc-kr 4 ?W "Coding System for fixed EUC Korean"
-		    (cons ccl-decode-fixed-euc-kr ccl-encode-fixed-euc-kr))
 
 ;; Chinese
+;;
+;; TODO: convert an obsolete make-coding-system to define-coding-system.
 
 (defconst egg-pinyin-shengmu
   '((""  . 0)  ("B" . 1)  ("C"  . 2)  ("Ch" . 3)  ("D" . 4)
@@ -828,9 +848,10 @@
 ;; Do not move the point, leave it where it was.
 (defmacro comm-accept-process-output ()
   `(let ((p (point)))
-     (if (null (accept-process-output proc comm-accept-timeout))
-	 (egg-error "backend timeout (comm-accept-process-output)"))
-     (goto-char p)))
+     (with-local-quit
+       (if (null (accept-process-output proc comm-accept-timeout))
+	   (egg-error "backend timeout (comm-accept-process-output)"))
+       (goto-char p))))
 
 (defmacro comm-require-process-output (n)
   `(if (< (point-max) (+ (point) ,n))
@@ -839,10 +860,11 @@
 (defun comm-wait-for-space (proc n)
   (let ((p (point))
 	(r (+ (point) n)))
-    (while (< (point-max) r)
-      (if (null (accept-process-output proc comm-accept-timeout))
-	  (egg-error "backend timeout (comm-wait-for-space)"))
-      (goto-char p))))
+    (with-local-quit
+      (while (< (point-max) r)
+	(if (null (accept-process-output proc comm-accept-timeout))
+	    (egg-error "backend timeout (comm-wait-for-space)"))
+	(goto-char p)))))
 
 (defmacro comm-following+forward-char ()
   `(prog1
