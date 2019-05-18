--- src-util/anthy.el.orig	2008-11-29 12:46:00 UTC
+++ src-util/anthy.el
@@ -161,11 +161,9 @@
 
 ;; From skk-macs.el From viper-util.el.  Welcome!
 (defmacro anthy-deflocalvar (var default-value &optional documentation)
-  (` (progn
-       (defvar (, var) (, default-value)
-	 (, (format "%s\n\(buffer local\)" documentation)))
-       (make-variable-buffer-local '(, var))
-       )))
+  `(defvar ,var ,default-value
+         ,(format "%s\n\(buffer local\)" documentation))
+       )
 
 ;; buffer local variables
 (anthy-deflocalvar anthy-context-id nil "コンテキストのid")
@@ -745,7 +743,7 @@
 	(if anthy-agent-process
 	    (kill-process anthy-agent-process))
 	(setq anthy-agent-process proc)
-	(process-kill-without-query proc)
+	(set-process-query-on-exit-flag proc nil)
 	(if anthy-xemacs
 	    (if (coding-system-p (find-coding-system 'euc-japan))
 		(set-process-coding-system proc 'euc-japan 'euc-japan))
@@ -892,7 +890,7 @@
 	 ((event-matches-key-specifier-p event 'backspace) 8)
 	 (t
 	  (char-to-int (event-to-character event)))))
-    last-command-char))
+    last-command-event))
 
 ;;
 ;;
