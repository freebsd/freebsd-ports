
$FreeBSD$

--- lib/srfi/srfi-8.scm.orig	Tue Jun 25 23:53:35 2002
+++ lib/srfi/srfi-8.scm	Sat Aug 17 22:34:33 2002
@@ -22,7 +22,8 @@
 (cond
  ((or (string=? "1.3" (version))
       (string=? "1.3.4" (version))
-      (string=? "1.4" (substring (version) 0 3)))
+      (string=? "1.4" (substring (version) 0 3))
+      (string=? "1.4.1" (version)))
   
   (use-modules (ice-9 slib))
   (require 'macro-by-example)
