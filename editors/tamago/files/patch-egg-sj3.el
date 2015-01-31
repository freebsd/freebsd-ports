--- egg/sj3.el.orig	2015-01-31 19:23:34.000000000 +0900
+++ egg/sj3.el	2015-01-31 19:25:52.000000000 +0900
@@ -146,7 +146,7 @@
 	(setq proc (open-network-stream "SJ3" buf hostname sj3-server-port))
       ((error quit)
        (egg-error "failed to connect sj3 server")))
-    (process-kill-without-query proc)
+    (set-process-query-on-exit-flag proc nil)
     (set-process-coding-system proc 'binary 'binary)
     (set-marker-insertion-type (process-mark proc) t)
     (save-excursion
