Index: egg/canna.el
diff -u egg/canna.el.orig egg/canna.el
--- egg/canna.el.orig	Wed Feb 23 21:57:47 2005
+++ egg/canna.el	Wed Feb 23 21:58:47 2005
@@ -360,13 +360,12 @@
 		      (setq proc (make-network-process :name proc-name :buffer buf :host host :service port :family family))
 		    ((error quit)))
 		; for old emacs (<= 21.3) bellow
-		(setq proc
-		      (cond ((string-match "^unix/" hostname)
-			     (let ((process-connection-type nil))
-			       (start-process proc-name buf egg-canna-icanna-path)))
-			    (condition-case nil
-				(open-network-stream proc-name buf hostname port)
-			      (error nil))))))
+		(if (string-match "^unix/" hostname)
+		    (let ((process-connection-type nil))
+		      (setq proc (start-process proc-name buf egg-canna-icanna-path)))
+		  (condition-case nil
+		      (setq proc (open-network-stream proc-name buf hostname port))
+		    (error quit)))))
 	    (when (processp proc)
 	      (process-kill-without-query proc)
 	      (set-process-coding-system proc 'binary 'binary)
