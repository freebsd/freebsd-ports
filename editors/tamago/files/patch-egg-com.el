--- egg-com.el.orig	2013-04-23 16:10:35.000000000 +0900
+++ egg-com.el	2013-04-23 16:13:12.000000000 +0900
@@ -828,9 +828,10 @@
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
@@ -839,10 +840,11 @@
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
