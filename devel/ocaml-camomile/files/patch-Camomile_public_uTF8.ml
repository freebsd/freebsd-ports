--- Camomile/public/uTF8.ml.orig	2019-08-08 07:10:33 UTC
+++ Camomile/public/uTF8.ml
@@ -194,7 +194,7 @@ let iter proc s = iter_aux proc s 0
 
 let iter proc s = iter_aux proc s 0
 
-let compare s1 s2 = Pervasives.compare s1 s2
+let compare s1 s2 = Stdlib.compare s1 s2
 
 exception Malformed_code
 
