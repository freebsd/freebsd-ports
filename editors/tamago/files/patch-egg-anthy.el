--- egg/anthy.el.orig	2015-01-31 19:24:09.000000000 +0900
+++ egg/anthy.el	2015-02-02 00:32:09.000000000 +0900
@@ -146,12 +146,11 @@
 		     (if anthy-egg-use-utf8
 			 '("--egg" "--utf8")
 		       '("--egg"))))
-	(process-kill-without-query anthy-egg-proc)
+	(set-process-query-on-exit-flag anthy-egg-proc nil)
 	(set-process-coding-system anthy-egg-proc cs cs)
 	(set-process-sentinel anthy-egg-proc 'anthy-egg-proc-sentinel)
 	(set-marker-insertion-type (process-mark anthy-egg-proc) t)
-	(save-excursion
-	  (set-buffer buf)
+	(with-current-buffer buf
 	  (erase-buffer)
 	  (buffer-disable-undo))
 	(anthyipc-get-greeting anthy-egg-proc)))
@@ -404,8 +403,7 @@
   (let ((buf (get-buffer-create anthy-egg-dic-buffer-name))
 	(cs (if anthy-egg-use-utf8 'utf-8-unix 'euc-japan-unix))
 	proc)
-    (save-excursion
-      (set-buffer buf)
+    (with-current-buffer buf
       (setq proc (apply 'start-process "anthy-egg-dic" buf
 			anthy-egg-dic-util-command
 			(if anthy-egg-use-utf8
