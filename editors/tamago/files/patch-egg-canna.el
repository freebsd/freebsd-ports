--- egg/canna.el.orig	2015-01-31 19:24:09.000000000 +0900
+++ egg/canna.el	2015-01-31 19:39:19.000000000 +0900
@@ -337,7 +337,7 @@
 		    (setq port (substring hostname (match-end 0))
 			  hostname (substring hostname 0 (match-beginning 0))))
 		  (if (and (stringp port) (string-match "^[0-9]+$" port))
-		      (setq port (string-to-int port)))
+		      (setq port (string-to-number port)))
 		  (and (equal hostname "")
 		       (setq hostname (or (getenv "CANNAHOST") "localhost")))
 		  (setq host hostname)
@@ -367,7 +367,7 @@
 		      (setq proc (open-network-stream proc-name buf hostname port))
 		    (error quit)))))
 	    (when (processp proc)
-	      (process-kill-without-query proc)
+	      (set-process-query-on-exit-flag proc nil)
 	      (set-process-coding-system proc 'binary 'binary)
 	      (set-process-sentinel proc 'canna-comm-sentinel)
 	      (set-marker-insertion-type (process-mark proc) t)
@@ -869,7 +869,7 @@
     (setq kouho-list (cdr (reverse kouho-list)))
     (setq kouho-list (reverse kouho-list))
     (setq i 0)
-    (setq kouho-list (mapcar '(lambda (k)
+    (setq kouho-list (mapcar #'(lambda (k)
 				(prog1
 				    (cons k i)
 				  (setq i (1+ i))))
