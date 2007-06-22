--- egg/wnnrpc.el	Sat Jun 16 23:30:29 2007
+++ egg/wnnrpc.el	Sat Jun 16 23:29:00 2007
@@ -714,8 +714,14 @@
      ,send-expr ,@rcv-exprs))
 
 (defmacro wnnrpc-get-result (&rest body)
-  `(let (result)
-     (comm-unpack (u) result)
+  `(let (result resulth)
+     (comm-unpack (w w) resulth result)
+     (cond ((and (= result 65535) (= resulth 65535))
+	    (setq result -1))
+	   ((= resulth (lsh (lsh resulth 16) -16))
+	    (setq result (+ (lsh resulth 16) result)))
+	   (t
+	    (error "overflow")))
      (if (< result 0)
        (progn
 	 (comm-unpack (u) result)


