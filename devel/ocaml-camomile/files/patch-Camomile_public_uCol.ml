--- Camomile/public/uCol.ml.orig	2019-08-08 07:10:33 UTC
+++ Camomile/public/uCol.ml
@@ -52,14 +52,14 @@ sig
       If [prec] is omitted, the maximum possible strength is used.
       If [variable] is omitted, the default of the locale
       (usually [`Shifted]) is used.
-      The meaning of the returned value is similar to Pervasives.compare *)
+      The meaning of the returned value is similar to Stdlib.compare *)
   val compare :
     ?locale:string -> ?prec:precision -> ?variable:variable_option ->
     text -> text -> int
 
   (** Binary comparison of sort_key gives the same result as [compare].
       i.e.
-      [compare t1 t2 = Pervasives.compare (sort_key t1) (sort_key t2)]
+      [compare t1 t2 = Stdlib.compare (sort_key t1) (sort_key t2)]
       If the same texts are repeatedly compared,
       pre-computation of sort_key gives better performance. *)
   val sort_key :
@@ -731,7 +731,7 @@ module Make (Config : ConfigInt.Type) (Text : UnicodeS
       | _ ->
         let key1 = key_of_inc prec col_info x1 in
         let key2 = key_of_inc prec col_info x2 in
-        Pervasives.compare key1 key2
+        Stdlib.compare key1 key2
 
   let compare ?locale ?prec ?variable t1 t2 =
     let col_info =
@@ -782,7 +782,7 @@ module Make (Config : ConfigInt.Type) (Text : UnicodeS
       | _ ->
         let key = key_of_inc prec col_info x in
         (*      Printf.printf "key_of_inc %s\n" (String.escaped key);*)
-        Pervasives.compare k key
+        Stdlib.compare k key
 
   let compare_with_key ?locale ?prec ?variable k t =
     let col_info =
