--- camlp4/Camlp4/Debug.ml.orig	2019-08-07 13:03:46 UTC
+++ camlp4/Camlp4/Debug.ml
@@ -29,7 +29,7 @@ value out_channel =
     open_out_gen [Open_wronly; Open_creat; Open_append; Open_text]
                  0o666 f
   with
-  [ Not_found -> Pervasives.stderr ];
+  [ Not_found -> Stdlib.stderr ];
 
 module StringSet = Set.Make String;
 
