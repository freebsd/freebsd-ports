--- lisp/xtla-defs.el.orig	Sat Jul  9 04:01:48 2005
+++ lisp/xtla-defs.el	Wed Jul 20 09:43:15 2005
@@ -1758,14 +1758,14 @@
 
 (defcustom tla-diff-executable (tla--first-set
                                 tla-site-diff-executable
-                                "diff")
+                                "gdiff")
   "*The name of the diff executable."
   :type 'string
   :group 'xtla)
 
 (defcustom tla-patch-executable (tla--first-set
                                  tla-site-patch-executable
-                                 "patch")
+                                 "gpatch")
   "*The name of the patch executable."
   :type 'string
   :group 'xtla)
