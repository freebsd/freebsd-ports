--- src-util/anthy.el.orig	2019-07-05 02:37:13 UTC
+++ src-util/anthy.el
@@ -745,7 +745,7 @@
 	(if anthy-agent-process
 	    (kill-process anthy-agent-process))
 	(setq anthy-agent-process proc)
-	(process-kill-without-query proc)
+	(set-process-query-on-exit-flag proc nil)
 	(if anthy-xemacs
 	    (if (coding-system-p (find-coding-system 'euc-japan))
 		(set-process-coding-system proc 'euc-japan 'euc-japan))
