--- lisp/ndjitsuu.el.orig	2026-09-07 07:19:54 UTC
+++ lisp/ndjitsuu.el
@@ -432,7 +432,7 @@
    (decode-coding-string
     (string-make-unibyte
      (ccl-execute-on-string 
-      'ndjitsuu-decode (make-vector 9 nil)
+      'ndjitsuu-decode (obarray-make 9)
       (ndjitsuu-file-contents-literally
        file from length))) 'cp932)))
 
