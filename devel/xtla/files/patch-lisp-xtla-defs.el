--- lisp/xtla-defs.el.orig	Sun Nov  7 17:53:03 2004
+++ lisp/xtla-defs.el	Thu Nov 11 09:15:52 2004
@@ -1605,13 +1605,13 @@
   :group 'xtla)
 
 ;;;###autoload
-(defcustom tla-diff-executable "diff"
+(defcustom tla-diff-executable "gdiff"
   "*The name of the diff executable."
   :type 'string
   :group 'xtla)
 
 ;;;###autoload
-(defcustom tla-patch-executable "patch"
+(defcustom tla-patch-executable "gpatch"
   "*The name of the patch executable."
   :type 'string
   :group 'xtla)
