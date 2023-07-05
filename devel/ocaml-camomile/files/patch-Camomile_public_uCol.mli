--- Camomile/public/uCol.mli.orig	2019-08-08 07:10:33 UTC
+++ Camomile/public/uCol.mli
@@ -65,14 +65,14 @@ sig
       	      If [prec] is omitted, the maximum possible strength is used.
       	      If [variable] is omitted, the default of the locale 
       	      (usually [`Shifted]) is used.
-      	      The meaning of the returned value is similar to Pervasives.compare *)
+      	      The meaning of the returned value is similar to Stdlib.compare *)
   val compare : 
     ?locale:string -> ?prec:precision -> ?variable:variable_option -> 
     text -> text -> int
 
   (** Binary comparison of sort_key gives the same result as [compare]. 
       		  i.e.
-      		  [compare t1 t2 = Pervasives.compare (sort_key t1) (sort_key t2)]
+      		  [compare t1 t2 = Stdlib.compare (sort_key t1) (sort_key t2)]
       		  If the same texts are repeatedly compared, 
       		  pre-computation of sort_key gives better performance. *)
   val sort_key : 
