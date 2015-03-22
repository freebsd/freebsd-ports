--- contrib/sb-sprof/test.lisp.orig	2015-02-27 19:49:46.000000000 +0900
+++ contrib/sb-sprof/test.lisp	2015-03-07 18:19:20.000000000 +0900
@@ -41,9 +41,9 @@
       (loop while (< (get-universal-time) target)
             do (consalot)))))
 
-#-(or win32 darwin)                    ;not yet
+#-(or win32 darwin freebsd)                    ;not yet
 (test)
-#-(or win32 darwin)                    ;not yet
+#-(or win32 darwin freebsd)                    ;not yet
 (consing-test)
 
 ;; For debugging purposes, print output for visual inspection to see if
