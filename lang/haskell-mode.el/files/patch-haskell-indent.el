--- ./haskell-indent.el.orig	Sat Feb 10 06:55:43 2007
+++ ./haskell-indent.el	Mon Feb 12 00:05:35 2007
@@ -316,7 +316,7 @@

 (defcustom haskell-indent-look-past-empty-line t
   "If nil, indentation engine will not look past an empty line for layout points."
-  :trype 'boolean)
+  :type 'boolean)

 (defun haskell-indent-start-of-def ()
   "Return the position of the start of a definition.
