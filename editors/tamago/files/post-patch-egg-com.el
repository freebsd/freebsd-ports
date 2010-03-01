--- egg-com.el.2	2010-03-02 05:19:01.000000000 +0900
+++ egg-com.el	2010-03-02 05:19:04.000000000 +0900
@@ -44,8 +44,65 @@
 
 ;; Japanese
 
+(defun fixed-euc-jp-pre-write-conversion (from to)
+   (let ((work-buf (generate-new-buffer " *temp*"))
+ 	ch)
+     (if (stringp from)
+ 	(encode-coding-string from 'euc-japan nil work-buf)
+       (encode-coding-region from to 'euc-japan work-buf))
+     (set-buffer work-buf)
+     (set-buffer-multibyte nil)
+     (goto-char (point-min))
+     (while (not (eobp))
+       (setq ch (following-char))
+       (cond ((= ch #x8E)		; SS2 for JISX0201-kana
+ 	     (delete-char 1)		; SS2 BYTE -> 0 BYTE&0x7F
+ 	     (insert 0)
+ 	     (forward-char 1))
+ 	    ((= ch #x8F)		; SS3 for JISX0212
+ 	     (delete-char 1)		; SS3 BYTE1 BYTE2 -> BYTE1 BYTE2&0x7F
+ 	     (forward-char 1)
+ 	     (setq ch (following-char))
+ 	     (delete-char 1)
+ 	     (insert (logand ch #x7F)))
+ 	    ((>= ch #xA0)		; JISX0208
+ 	     (forward-char 2))
+ 	    (t				; ASCII
+ 	     (insert 0)			; BYTE -> 0 BYTE
+ 	     (forward-char 1))))))
+ 
+(defun fixed-euc-jp-post-read-conversion (len)
+   (let ((str (string-as-unibyte (buffer-substring (point) (+ (point) len))))
+ 	(pos (point))
+ 	i ch1 ch2)
+     (delete-region (point) (+ (point) len))
+     (setq i 0)
+     (while (< i len)
+       (setq ch1 (aref str i))
+       (setq ch2 (aref str (1+ i)))
+       (cond ((>= ch1 #x80)
+ 	     (if (>= ch2 #x80)
+ 		 (setq ch1 		; JISX0208
+ 		       (decode-char 'japanese-jisx0208
+ 				    (logior (lsh (logand ch1 #x7F) 8)
+ 					    (logand ch2 #x7F))))
+ 	       (setq ch1		; JISX0212
+ 		     (decode-char 'japanese-jisx0212
+ 				  (logior (lsh (logand ch1 #x7F) 8) ch2)))))
+ 	    (t
+ 	     (if (>= ch2 #x80)
+ 		 (setq ch1		; JISX0201-kana
+ 		       (decode-char 'katakana-jisx0201 (logand ch2 #x7F)))
+ 	       (setq ch1 ch2))))
+       (insert ch1)
+       (setq i (+ i 2)))
+     (prog1 (- (point) pos)
+       (goto-char pos))))
+ 
 (eval-and-compile
-(define-ccl-program ccl-decode-fixed-euc-jp
+  (if (string< mule-version "6.0")
+    (progn
+      (define-ccl-program ccl-decode-fixed-euc-jp
   `(2
     ((r2 = ,(charset-id 'japanese-jisx0208))
      (r3 = ,(charset-id 'japanese-jisx0212))
@@ -96,11 +153,24 @@
 	   (write-read-repeat r0)))
       (read r0)
       (repeat)))))
-)
 
 (make-coding-system 'fixed-euc-jp 4 ?W "Coding System for fixed EUC Japanese"
 		    (cons ccl-decode-fixed-euc-jp ccl-encode-fixed-euc-jp))
-
+)
+    (define-charset 'fixed-euc-jp
+      "Fixed EUC Japanese"
+      :dimension 2
+      :superset '(ascii
+                 (katakana-jisx0201 . #x80)
+                 (japanese-jisx0208 . #x8080)
+                 (japanese-jisx0212 . #x8000)))
+    (define-coding-system 'fixed-euc-jp
+      "Coding System for fixed EUC Japanese"
+      :mnemonic ?W
+      :coding-type 'charset
+      :charset-list '(fixed-euc-jp))
+    )
+)
 ;; Korean
 
 (eval-and-compile
