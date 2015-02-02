--- egg-sim.el.orig	2015-01-31 19:23:34.000000000 +0900
+++ egg-sim.el	2015-01-31 19:25:52.000000000 +0900
@@ -56,19 +56,23 @@
 	 (<= to max)
 	 (cond ((= (charset-dimension charset) 1)
 		(while (<= from to)
-		  (setq result (cons (char-to-string
-				      (make-char charset to))
-				     result)
-			to (1- to)))
+		  (let ((c (ignore-errors (make-char charset to))))
+		    (if c (progn
+			    (setq result (cons
+					  (char-to-string c)
+					  result)))))
+		  (setq to (1- to)))
 		result)
 	       ((= (charset-dimension charset) 2)
 		(while (<= from to)
 		  (let ((code max))
 		    (while (<= min code)
-		      (setq result (cons (char-to-string
-					  (make-char charset to code))
-					 result)
-			    code (1- code))))
+		      (let ((c (ignore-errors (make-char charset to code))))
+		        (if c (progn
+				(setq result (cons
+					      (char-to-string c)
+					      result)))))
+		      (setq code (1- code))))
 		  (setq to (1- to)))
 		result)))))
 
@@ -432,7 +436,7 @@
     (insert "-+")
     (let ((i 0))
       (while (< i 16)
-	(insert (format "----" i))
+	(insert (format "----"))
 	(setq i (1+ i))))
     (insert "\n")
 
@@ -461,7 +465,7 @@
     (insert "-+")
     (let ((i 0))
       (while (< i 16)
-	(insert (format "----" i))
+	(insert (format "----"))
 	(setq i (1+ i))))
     (insert "\n")
 
@@ -496,7 +500,7 @@
     (insert "-+")
     (let ((i 0))
       (while (< i 16)
-	(insert (format "----" i))
+	(insert (format "----"))
 	(setq i (1+ i))))
     (insert "\n")
 
@@ -531,7 +535,7 @@
     (insert "-+")
     (let ((i 1))
       (while (<= i 94)
-	(insert (format "-----" i))
+	(insert (format "-----"))
 	(setq i (1+ i))))
     (insert "\n")
 
