--- egg-sim.el.orig	2014-11-23 15:19:11.000000000 +0900
+++ egg-sim.el	2014-11-23 15:20:02.000000000 +0900
@@ -432,7 +432,7 @@
     (insert "-+")
     (let ((i 0))
       (while (< i 16)
-	(insert (format "----" i))
+	(insert (format "----"))
 	(setq i (1+ i))))
     (insert "\n")
 
@@ -461,7 +461,7 @@
     (insert "-+")
     (let ((i 0))
       (while (< i 16)
-	(insert (format "----" i))
+	(insert (format "----"))
 	(setq i (1+ i))))
     (insert "\n")
 
@@ -496,7 +496,7 @@
     (insert "-+")
     (let ((i 0))
       (while (< i 16)
-	(insert (format "----" i))
+	(insert (format "----"))
 	(setq i (1+ i))))
     (insert "\n")
 
@@ -531,7 +531,7 @@
     (insert "-+")
     (let ((i 1))
       (while (<= i 94)
-	(insert (format "-----" i))
+	(insert (format "-----"))
 	(setq i (1+ i))))
     (insert "\n")
 
