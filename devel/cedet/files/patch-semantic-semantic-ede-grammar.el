--- semantic/semantic-ede-grammar.el.orig	Mon Nov 13 11:46:53 2006
+++ semantic/semantic-ede-grammar.el	Mon Nov 13 11:47:29 2006
@@ -191,15 +191,15 @@
 (autoload 'ede-proj-target-elisp "semantic-ede-proj-target-grammar"
   "Target class for Emacs/Semantic grammar files." nil nil)
 
+(ede-proj-register-target "semantic grammar"
+			  semantic-ede-proj-target-grammar)
+
+(provide 'semantic-ede-grammar)
+
 ;;;###autoload
 (eval-after-load "ede-proj"
     (quote
      (require 'semantic-ede-grammar)
      ))
-
-(ede-proj-register-target "semantic grammar"
-			  semantic-ede-proj-target-grammar)
-
-(provide 'semantic-ede-grammar)
 
 ;;; semantic-ede-grammar.el ends here
