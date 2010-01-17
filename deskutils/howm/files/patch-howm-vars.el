--- howm-vars.el.orig	2010-01-18 00:13:34.830023820 +0900
+++ howm-vars.el	2010-01-18 00:13:50.346324312 +0900
@@ -657,7 +657,7 @@
 This variable is obsolete and may be removed in future.")
 (defvar howm-view-grep-default-option
   (concat "-Hnr "
-          (mapconcat (lambda (d) (concat "--exclude-dir=" d))
+          (mapconcat (lambda (d) (concat "--exclude=" d))
                      howm-excluded-dirs " ")))
 (howm-defcustom-risky howm-view-grep-option howm-view-grep-default-option
   "*Common grep option for howm."
