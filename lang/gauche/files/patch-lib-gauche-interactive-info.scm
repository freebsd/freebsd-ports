--- lib/gauche/interactive/info.scm.orig	Fri Jul 12 15:57:01 2002
+++ lib/gauche/interactive/info.scm	Thu Oct 24 11:28:44 2002
@@ -61,9 +61,9 @@
                         (else '())))
          (instpath 
           (let1 pathcomps (string-split (gauche-library-directory) #\/)
-            (if (> (length pathcomps) 3)
+            (if (> (length pathcomps) 4)
                 (list (apply build-path
-                             (append (drop-right pathcomps 3) '("info"))))
+                             (append (drop-right pathcomps 4) '("info"))))
                 '())))
          (in-place (list "../doc")))
     (append syspath instpath in-place)))
