--- lisp/net/tramp-archive.el.orig	2026-07-07 12:37:38 UTC
+++ lisp/net/tramp-archive.el
@@ -741,6 +741,20 @@ offered."
      v 'remote-file-error
      "Operation `%s' not implemented for file archives" operation)))
 
+;;; Default connection-local variables for Tramp.
+
+(defconst tramp-archive-connection-local-default-variables
+  '((tramp-allow-double-percent . t))
+  "Default connection-local variables for file archives.")
+
+(connection-local-set-profile-variables
+ 'tramp-archive-connection-local-default-profile
+ tramp-archive-connection-local-default-variables)
+
+(connection-local-set-profiles
+ `(:application tramp :protocol ,tramp-archive-method)
+ 'tramp-archive-connection-local-default-profile)
+
 (add-hook 'tramp-unload-hook
 	  (lambda ()
 	    (unload-feature 'tramp-archive 'force)))
