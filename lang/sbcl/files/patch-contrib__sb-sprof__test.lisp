--- contrib/sb-sprof/test.lisp.orig	2013-02-26 06:42:18.000000000 -0500
+++ contrib/sb-sprof/test.lisp	2013-03-22 14:29:52.000000000 -0400
@@ -1,9 +1,9 @@
 (in-package :cl-user)
 (require :sb-sprof)
 
-#-(or win32 darwin)                    ;not yet
+#-(or win32 darwin freebsd)                    ;not yet
 (sb-sprof::test)
-#-(or win32 darwin)                    ;not yet
+#-(or win32 darwin freebsd)                    ;not yet
 (sb-sprof::consing-test)
 
 ;; For debugging purposes, print output for visual inspection to see if
