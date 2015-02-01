--- egg/canna.el.orig	2015-01-31 19:24:09.000000000 +0900
+++ egg/canna.el	2015-02-02 00:52:59.000000000 +0900
@@ -134,7 +134,7 @@
 (defun canna-make-backend (lang env &optional source-lang converted-lang)
   (let ((finalize (canna-backend-func-name "canna-finalize-backend" lang))
 	(backend (canna-backend-func-name "canna-backend" lang env)))
-    (if (null (fboundp finalize))
+    (if (null (fboundp 'finalize))
 	(progn
 	  (fset finalize (function (lambda () (canna-finalize-backend))))
 	  (egg-set-finalize-backend (list finalize))))
@@ -319,8 +319,7 @@
     (unwind-protect
 	(progn
 	  (setq buf (generate-new-buffer " *CANNA*"))
-    (save-excursion
-      (set-buffer buf)
+    (with-current-buffer buf
       (erase-buffer)
       (buffer-disable-undo)
 	    (set-buffer-multibyte nil)
@@ -337,7 +336,7 @@
 		    (setq port (substring hostname (match-end 0))
 			  hostname (substring hostname 0 (match-beginning 0))))
 		  (if (and (stringp port) (string-match "^[0-9]+$" port))
-		      (setq port (string-to-int port)))
+		      (setq port (string-to-number port)))
 		  (and (equal hostname "")
 		       (setq hostname (or (getenv "CANNAHOST") "localhost")))
 		  (setq host hostname)
@@ -367,7 +366,7 @@
 		      (setq proc (open-network-stream proc-name buf hostname port))
 		    (error quit)))))
 	    (when (processp proc)
-	      (process-kill-without-query proc)
+	      (set-process-query-on-exit-flag proc nil)
 	      (set-process-coding-system proc 'binary 'binary)
 	      (set-process-sentinel proc 'canna-comm-sentinel)
 	      (set-marker-insertion-type (process-mark proc) t)
@@ -869,7 +868,7 @@
     (setq kouho-list (cdr (reverse kouho-list)))
     (setq kouho-list (reverse kouho-list))
     (setq i 0)
-    (setq kouho-list (mapcar '(lambda (k)
+    (setq kouho-list (mapcar #'(lambda (k)
 				(prog1
 				    (cons k i)
 				  (setq i (1+ i))))
