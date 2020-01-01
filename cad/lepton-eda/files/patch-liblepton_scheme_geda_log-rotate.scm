--- liblepton/scheme/geda/log-rotate.scm.orig	2019-10-03 20:45:55 UTC
+++ liblepton/scheme/geda/log-rotate.scm
@@ -44,7 +44,7 @@
 ;; FIXME This should be obtained from the code that decides where to
 ;; create and populate log files.
 (define (log-directory)
-  (string-append (user-config-dir) file-name-separator-string "logs"))
+  (string-append (user-cache-dir) file-name-separator-string "logs"))
 
 ;;;; get-log-toolname path
 ;;
