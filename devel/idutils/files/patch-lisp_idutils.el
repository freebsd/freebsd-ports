--- lisp/idutils.el.orig	2021-02-27 07:27:26 UTC
+++ lisp/idutils.el
@@ -32,7 +32,7 @@
 (require 'compile)
 (require 'thingatpt)
 
-(defvar gid-command "gid" "The command run by the gid function.")
+(defvar gid-command "ggid" "The command run by the gid function.")
 
 (defvar gid-mode-font-lock-keywords
   '(("^\\(Compilation\\|Gid\\) \\(started\\|finished\\).*"
