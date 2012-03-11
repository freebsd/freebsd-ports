--- howm-vars.el.orig	2011-08-23 20:48:27.000000000 +0900
+++ howm-vars.el	2012-03-11 22:18:42.730947048 +0900
@@ -679,7 +679,7 @@
   "*Command name for fgrep.
 This variable is obsolete and may be removed in future.")
 (defvar howm-view-grep-default-option
-  (labels ((ed (d) (concat "--exclude-dir=" d)))
+  (labels ((ed (d) (concat "--exclude=" d)))
     (let* ((has-ed (condition-case nil
                        (eq 0 (call-process howm-view-grep-command nil nil nil
                                            (ed "/") "--version"))
