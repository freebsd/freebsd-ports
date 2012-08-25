Index: hex-util.el
===================================================================
--- hex-util.el	(revision 2)
+++ hex-util.el	(working copy)
@@ -28,14 +28,14 @@
 
 (eval-when-compile
   (defmacro hex-char-to-num (chr)
-    (` (let ((chr (, chr)))
-	 (cond
-	  ((and (<= ?a chr)(<= chr ?f)) (+ (- chr ?a) 10))
-	  ((and (<= ?A chr)(<= chr ?F)) (+ (- chr ?A) 10))
-	  ((and (<= ?0 chr)(<= chr ?9)) (- chr ?0))
-	  (t (error "Invalid hexadecimal digit `%c'" chr))))))
+    `(let ((chr ,chr))
+       (cond
+	((and (<= ?a chr)(<= chr ?f)) (+ (- chr ?a) 10))
+	((and (<= ?A chr)(<= chr ?F)) (+ (- chr ?A) 10))
+	((and (<= ?0 chr)(<= chr ?9)) (- chr ?0))
+	(t (error "Invalid hexadecimal digit `%c'" chr)))))
   (defmacro num-to-hex-char (num)
-    (` (aref "0123456789abcdef" (, num)))))
+    `(aref "0123456789abcdef" ,num)))
 
 (defun decode-hex-string (string)
   "Decode hexadecimal STRING to octet string."
