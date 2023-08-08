--- Camomile/public/uCS4.ml.orig	2019-08-08 07:10:33 UTC
+++ Camomile/public/uCS4.ml
@@ -140,5 +140,5 @@ let compare (a:t) (b:t) =
 
 let compare (a:t) (b:t) =
   match Array1.dim a - Array1.dim b with
-    0 -> Pervasives.compare a b
+    0 -> Stdlib.compare a b
   | sgn -> sgn
