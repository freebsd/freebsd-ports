Index: sha1-el.el
===================================================================
--- sha1-el.el.orig	2007-09-05 23:39:48 UTC
+++ sha1-el.el
@@ -125,91 +125,91 @@ If this variable is set to nil, use inte
 
 ;;; original definition of sha1-F0.
 ;;; (defmacro sha1-F0 (B C D)
-;;;   (` (logior (logand (, B) (, C))
-;;; 	     (logand (lognot (, B)) (, D)))))
+;;;   `(logior (logand ,B ,C)
+;;; 	     (logand (lognot ,B) ,D)))
 ;;; a little optimization from GnuPG/cipher/sha1.c.
   (defmacro sha1-F0 (B C D)
-    (` (logxor (, D) (logand (, B) (logxor (, C) (, D))))))
+    `(logxor ,D (logand ,B (logxor ,C ,D))))
   (defmacro sha1-F1 (B C D)
-    (` (logxor (, B) (, C) (, D))))
+    `(logxor ,B ,C ,D))
 ;;; original definition of sha1-F2.
 ;;; (defmacro sha1-F2 (B C D)
-;;;   (` (logior (logand (, B) (, C))
-;;; 	     (logand (, B) (, D))
-;;; 	     (logand (, C) (, D)))))
+;;;   `(logior (logand ,B ,C)
+;;; 	     (logand ,B ,D)
+;;; 	     (logand ,C ,D)))
 ;;; a little optimization from GnuPG/cipher/sha1.c.
   (defmacro sha1-F2 (B C D)
-    (` (logior (logand (, B) (, C))
-	       (logand (, D) (logior (, B) (, C))))))
+    `(logior (logand ,B ,C)
+	     (logand ,D (logior ,B ,C))))
   (defmacro sha1-F3 (B C D)
-    (` (logxor (, B) (, C) (, D))))
+    `(logxor ,B ,C ,D))
 
   (defmacro sha1-S1  (W-high W-low)
-    (` (let ((W-high (, W-high))
-	     (W-low  (, W-low)))
-	 (setq S1W-high (+ (% (* W-high 2) 65536)
-			   (/ W-low (, (/ 65536 2)))))
-	 (setq S1W-low (+ (/ W-high (, (/ 65536 2)))
-			  (% (* W-low 2) 65536))))))
+    `(let ((W-high ,W-high)
+	   (W-low  ,W-low))
+       (setq S1W-high (+ (% (* W-high 2) 65536)
+			 (/ W-low ,(/ 65536 2))))
+       (setq S1W-low (+ (/ W-high ,(/ 65536 2))
+			(% (* W-low 2) 65536)))))
   (defmacro sha1-S5  (A-high A-low)
-    (` (progn
-	 (setq S5A-high (+ (% (* (, A-high) 32) 65536)
-			   (/ (, A-low) (, (/ 65536 32)))))
-	 (setq S5A-low  (+ (/ (, A-high) (, (/ 65536 32)))
-			   (% (* (, A-low) 32) 65536))))))
+    `(progn
+       (setq S5A-high (+ (% (* ,A-high 32) 65536)
+			 (/ ,A-low ,(/ 65536 32))))
+       (setq S5A-low  (+ (/ ,A-high , (/ 65536 32))
+			 (% (* ,A-low 32) 65536)))))
   (defmacro sha1-S30 (B-high B-low)
-    (` (progn
-	 (setq S30B-high (+ (/ (, B-high) 4)
-			    (* (% (, B-low) 4) (, (/ 65536 4)))))
-	 (setq S30B-low  (+ (/ (, B-low) 4)
-			    (* (% (, B-high) 4) (, (/ 65536 4))))))))
+    `(progn
+       (setq S30B-high (+ (/ ,B-high 4)
+			  (* (% ,B-low 4) ,(/ 65536 4))))
+       (setq S30B-low  (+ (/ ,B-low 4)
+			  (* (% ,B-high 4) ,(/ 65536 4))))))
 
   (defmacro sha1-OP (round)
-    (` (progn
-	 (sha1-S5 sha1-A-high sha1-A-low)
-	 (sha1-S30 sha1-B-high sha1-B-low)
-	 (setq sha1-A-low (+ ((, (intern (format "sha1-F%d" round)))
-			      sha1-B-low sha1-C-low sha1-D-low)
-			     sha1-E-low
-			     (, (symbol-value
-				 (intern (format "sha1-K%d-low" round))))
-			     (aref block-low idx)
-			     (progn
-			       (setq sha1-E-low sha1-D-low)
-			       (setq sha1-D-low sha1-C-low)
-			       (setq sha1-C-low S30B-low)
-			       (setq sha1-B-low sha1-A-low)
-			       S5A-low)))
-	 (setq carry (/ sha1-A-low 65536))
-	 (setq sha1-A-low (% sha1-A-low 65536))
-	 (setq sha1-A-high (% (+ ((, (intern (format "sha1-F%d" round)))
-				  sha1-B-high sha1-C-high sha1-D-high)
-				 sha1-E-high
-				 (, (symbol-value
-				     (intern (format "sha1-K%d-high" round))))
-				 (aref block-high idx)
-				 (progn
-				   (setq sha1-E-high sha1-D-high)
-				   (setq sha1-D-high sha1-C-high)
-				   (setq sha1-C-high S30B-high)
-				   (setq sha1-B-high sha1-A-high)
-				   S5A-high)
-				 carry)
-			      65536)))))
+    `(progn
+       (sha1-S5 sha1-A-high sha1-A-low)
+       (sha1-S30 sha1-B-high sha1-B-low)
+       (setq sha1-A-low (+ (,(intern (format "sha1-F%d" round))
+			    sha1-B-low sha1-C-low sha1-D-low)
+			   sha1-E-low
+			   ,(symbol-value
+			     (intern (format "sha1-K%d-low" round)))
+			   (aref block-low idx)
+			   (progn
+			     (setq sha1-E-low sha1-D-low)
+			     (setq sha1-D-low sha1-C-low)
+			     (setq sha1-C-low S30B-low)
+			     (setq sha1-B-low sha1-A-low)
+			     S5A-low)))
+       (setq carry (/ sha1-A-low 65536))
+       (setq sha1-A-low (% sha1-A-low 65536))
+       (setq sha1-A-high (% (+ (,(intern (format "sha1-F%d" round))
+				sha1-B-high sha1-C-high sha1-D-high)
+			       sha1-E-high
+			       ,(symbol-value
+				 (intern (format "sha1-K%d-high" round)))
+			       (aref block-high idx)
+			       (progn
+				 (setq sha1-E-high sha1-D-high)
+				 (setq sha1-D-high sha1-C-high)
+				 (setq sha1-C-high S30B-high)
+				 (setq sha1-B-high sha1-A-high)
+				 S5A-high)
+			       carry)
+			    65536))))
 
   (defmacro sha1-add-to-H (H X)
-    (` (progn
-	 (setq (, (intern (format "sha1-%s-low" H)))
-	       (+ (, (intern (format "sha1-%s-low" H)))
-		  (, (intern (format "sha1-%s-low" X)))))
-	 (setq carry (/ (, (intern (format "sha1-%s-low" H))) 65536))
-	 (setq (, (intern (format "sha1-%s-low" H)))
-	       (% (, (intern (format "sha1-%s-low" H))) 65536))
-	 (setq (, (intern (format "sha1-%s-high" H)))
-	       (% (+ (, (intern (format "sha1-%s-high" H)))
-		     (, (intern (format "sha1-%s-high" X)))
-		     carry)
-		  65536)))))
+    `(progn
+       (setq ,(intern (format "sha1-%s-low" H))
+	     (+ ,(intern (format "sha1-%s-low" H))
+		,(intern (format "sha1-%s-low" X))))
+       (setq carry (/ ,(intern (format "sha1-%s-low" H)) 65536))
+       (setq ,(intern (format "sha1-%s-low" H))
+	     (% ,(intern (format "sha1-%s-low" H)) 65536))
+       (setq ,(intern (format "sha1-%s-high" H))
+	     (% (+ ,(intern (format "sha1-%s-high" H))
+		   ,(intern (format "sha1-%s-high" X))
+		   carry)
+		65536))))
   )
 
 ;;; buffers (H0 H1 H2 H3 H4).
