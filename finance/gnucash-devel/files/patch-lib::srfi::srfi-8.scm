
$FreeBSD$

--- lib/srfi/srfi-8.scm	2002/06/21 12:07:11	1.1
+++ lib/srfi/srfi-8.scm	2002/06/21 12:17:48
@@ -22,7 +22,8 @@
 (cond
  ((or (string=? "1.3" (version))
       (string=? "1.3.4" (version))
-      (string=? "1.4" (version)))
+      (string=? "1.4" (version))
+      (string=? "1.4.1" (version)))
   
   (use-modules (ice-9 slib))
   (require 'macro-by-example)
