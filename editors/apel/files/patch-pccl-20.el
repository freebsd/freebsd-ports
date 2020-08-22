--- pccl-20.el.orig	2019-04-07 10:56:27 UTC
+++ pccl-20.el
@@ -88,8 +88,9 @@ CODING-SYSTEM, DECODER and ENCODER must be symbol."
       (when-broken ccl-accept-symbol-as-program
 	(setq decoder (symbol-value decoder))
 	(setq encoder (symbol-value encoder)))
-      (make-coding-system coding-system 4 mnemonic docstring
-			  (cons decoder encoder)))
+    (if (fboundp 'make-coding-system)
+      (make-coding-system coding-system 4 mnemonic docstring (cons decoder encoder))
+      (define-coding-system coding-system docstring :mnemonic mnemonic :coding-type 'ccl :ccl-decoder decoder :ccl-encoder encoder)))
     )
 
   (when-broken ccl-accept-symbol-as-program
