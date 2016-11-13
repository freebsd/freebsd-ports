--- hmac-def.el.orig	2007-09-05 23:39:48 UTC
+++ hmac-def.el
@@ -39,46 +39,46 @@ a string and return a digest of it (in b
 B is a byte-length of a block size of H. (B=64 for both SHA1 and MD5.)
 L is a byte-length of hash outputs. (L=16 for MD5, L=20 for SHA1.)
 If BIT is non-nil, truncate output to specified bits."
-  (` (defun (, name) (text key)
-       (, (concat "Compute "
-		  (upcase (symbol-name name))
-		  " over TEXT with KEY."))
-       (let ((key-xor-ipad (make-string (, B) ?\x36))
-	     (key-xor-opad (make-string (, B) ?\x5C))
-	     (len (length key))
-	     (pos 0))
-	 (unwind-protect
-	     (progn
-	       ;; if `key' is longer than the block size, apply hash function
-	       ;; to `key' and use the result as a real `key'.
-	       (if (> len (, B))
-		   (setq key ((, H) key)
-			 len (, L)))
-	       (while (< pos len)
-		 (aset key-xor-ipad pos (logxor (aref key pos) ?\x36))
-		 (aset key-xor-opad pos (logxor (aref key pos) ?\x5C))
-		 (setq pos (1+ pos)))
-	       (setq key-xor-ipad (unwind-protect
-				      (concat key-xor-ipad text)
-				    (fillarray key-xor-ipad 0))
-		     key-xor-ipad (unwind-protect
-				      ((, H) key-xor-ipad)
-				    (fillarray key-xor-ipad 0))
-		     key-xor-opad (unwind-protect
-				      (concat key-xor-opad key-xor-ipad)
-				    (fillarray key-xor-opad 0))
-		     key-xor-opad (unwind-protect
-				      ((, H) key-xor-opad)
-				    (fillarray key-xor-opad 0)))
-	       ;; now `key-xor-opad' contains
-	       ;; H(KEY XOR opad, H(KEY XOR ipad, TEXT)).
-	       (, (if (and bit (< (/ bit 8) L))
-		      (` (substring key-xor-opad 0 (, (/ bit 8))))
-		    ;; return a copy of `key-xor-opad'.
-		    (` (concat key-xor-opad)))))
-	   ;; cleanup.
-	   (fillarray key-xor-ipad 0)
-	   (fillarray key-xor-opad 0))))))
+  `(defun ,name (text key)
+     ,(concat "Compute "
+              (upcase (symbol-name name))
+              " over TEXT with KEY.")
+     (let ((key-xor-ipad (make-string ,B ?\x36))
+           (key-xor-opad (make-string ,B ?\x5C))
+           (len (length key))
+           (pos 0))
+       (unwind-protect
+           (progn
+             ;; if `key' is longer than the block size, apply hash function
+             ;; to `key' and use the result as a real `key'.
+             (if (> len ,B)
+                 (setq key (,H key)
+                       len ,L))
+             (while (< pos len)
+               (aset key-xor-ipad pos (logxor (aref key pos) ?\x36))
+               (aset key-xor-opad pos (logxor (aref key pos) ?\x5C))
+               (setq pos (1+ pos)))
+             (setq key-xor-ipad (unwind-protect
+                                    (concat key-xor-ipad text)
+                                  (fillarray key-xor-ipad 0))
+                   key-xor-ipad (unwind-protect
+                                    (,H key-xor-ipad)
+                                  (fillarray key-xor-ipad 0))
+                   key-xor-opad (unwind-protect
+                                    (concat key-xor-opad key-xor-ipad)
+                                  (fillarray key-xor-opad 0))
+                   key-xor-opad (unwind-protect
+                                    (,H key-xor-opad)
+                                  (fillarray key-xor-opad 0)))
+             ;; now `key-xor-opad' contains
+             ;; H(KEY XOR opad, H(KEY XOR ipad, TEXT)).
+             ,(if (and bit (< (/ bit 8) L))
+                  `(substring key-xor-opad 0 ,(/ bit 8))
+                ;; return a copy of `key-xor-opad'.
+                `(concat key-xor-opad)))
+         ;; cleanup.
+         (fillarray key-xor-ipad 0)
+         (fillarray key-xor-opad 0)))))
 
 (provide 'hmac-def)
 
