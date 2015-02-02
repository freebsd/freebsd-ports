--- egg-cnv.el.orig	2015-01-31 19:23:34.000000000 +0900
+++ egg-cnv.el	2015-01-31 19:25:52.000000000 +0900
@@ -1245,7 +1245,8 @@
   (with-output-to-temp-buffer "*Help*"
     (princ "EGG Conversion mode:\n")
     (princ (documentation 'egg-conversion-mode))
-    (help-setup-xref (cons #'help-xref-mode (current-buffer)) (interactive-p))))
+    (help-setup-xref (cons #'help-xref-mode (current-buffer))
+      (called-interactively-p 'interactive))))
 
 (provide 'egg-cnv)
 
