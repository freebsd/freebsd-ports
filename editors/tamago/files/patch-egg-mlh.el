--- egg-mlh.el.orig	2015-01-31 19:23:34.000000000 +0900
+++ egg-mlh.el	2015-01-31 19:25:52.000000000 +0900
@@ -122,7 +122,7 @@
   (goto-char end-marker)
   (backward-delete-char 2)
   (let* ((str (buffer-substring beg (point)))
-         (val (string-to-int str)))
+         (val (string-to-number str)))
     (delete-region beg (point))
     (if (= val 0)
         (setq val 1))
@@ -220,7 +220,7 @@
   (goto-char end-marker)
   (backward-delete-char 2)
   (let* ((str (buffer-substring beg (point)))
-         (val (string-to-int str)))
+         (val (string-to-number str)))
     (delete-region beg (point))
     (if (= val 0)
         (setq val 1))
