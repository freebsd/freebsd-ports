--- egg/wnnrpc.el.orig	2015-01-31 19:24:10.000000000 +0900
+++ egg/wnnrpc.el	2015-01-31 19:25:52.000000000 +0900
@@ -714,8 +714,14 @@
      ,send-expr ,@rcv-exprs))
 
 (defmacro wnnrpc-get-result (&rest body)
-  `(let (result)
-     (comm-unpack (i) result)
+  `(let (result resulth)
+     (comm-unpack (w w) resulth result)
+     (cond ((and (= result 65535) (= resulth 65535))
+           (setq result -1))
+          ((= resulth (lsh (lsh resulth 16) -16))
+           (setq result (+ (lsh resulth 16) result)))
+          (t
+           (error "overflow")))
      (if (< result 0)
        (progn
 	 (comm-unpack (i) result)
