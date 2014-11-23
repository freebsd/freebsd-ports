--- egg/wnn.el.orig	2014-11-23 16:11:58.000000000 +0900
+++ egg/wnn.el	2014-11-23 16:12:19.000000000 +0900
@@ -1283,7 +1283,7 @@
                      (setq proc (open-network-stream proc-name buf hostname port))
                    (error quit)))))
            (when (processp proc)
-	      (process-kill-without-query proc)
+	      (set-process-query-on-exit-flag proc nil)
 	      (set-process-coding-system proc 'binary 'binary)
 	      (set-process-sentinel proc 'wnn-comm-sentinel)
 	      (set-marker-insertion-type (process-mark proc) t)
