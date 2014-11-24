--- egg-cnv.el.orig	2002-07-23 06:59:44.000000000 +0900
+++ egg-cnv.el	2014-11-23 16:00:50.000000000 +0900
@@ -1245,7 +1245,8 @@
   (with-output-to-temp-buffer "*Help*"
     (princ "EGG Conversion mode:\n")
     (princ (documentation 'egg-conversion-mode))
-    (help-setup-xref (cons #'help-xref-mode (current-buffer)) (interactive-p))))
+    (help-setup-xref (cons #'help-xref-mode (current-buffer))
+      (called-interactively-p 'interactive))))
 
 (provide 'egg-cnv)
 
