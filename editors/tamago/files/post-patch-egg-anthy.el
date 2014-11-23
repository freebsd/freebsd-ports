--- egg/anthy.el.orig	2014-11-23 16:11:09.000000000 +0900
+++ egg/anthy.el	2014-11-23 16:11:30.000000000 +0900
@@ -146,7 +146,7 @@
 		     (if anthy-egg-use-utf8
 			 '("--egg" "--utf8")
 		       '("--egg"))))
-	(process-kill-without-query anthy-egg-proc)
+	(set-process-query-on-exit-flag anthy-egg-proc nil)
 	(set-process-coding-system anthy-egg-proc cs cs)
 	(set-process-sentinel anthy-egg-proc 'anthy-egg-proc-sentinel)
 	(set-marker-insertion-type (process-mark anthy-egg-proc) t)
