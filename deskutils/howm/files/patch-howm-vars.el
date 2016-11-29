--- howm-vars.el.orig	2015-12-31 22:41:45.000000000 +0900
+++ howm-vars.el	2016-11-26 22:46:32.596292000 +0900
@@ -759,7 +759,7 @@
 This variable is obsolete and may be removed in future.")
 (defvar howm-view-grep-default-option
   ;; "labels" causes a trouble in git-head emacs (d5e3922) [2015-01-31]
-  (let* ((ed (lambda (d) (concat "--exclude-dir=" d)))
+  (let* ((ed (lambda (d) (concat "--exclude=" d)))
          (has-ed (condition-case nil
                      (eq 0 (call-process howm-view-grep-command nil nil nil
                                          (apply ed "/") "--version"))
