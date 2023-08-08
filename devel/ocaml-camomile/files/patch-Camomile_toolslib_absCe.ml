--- Camomile/toolslib/absCe.ml.orig	2019-08-08 07:10:33 UTC
+++ Camomile/toolslib/absCe.ml
@@ -49,7 +49,7 @@ type elt =
   | `FirstImplicit
   | `FirstTrailing ]
 
-module Elt = struct type t = elt let compare = Pervasives.compare end
+module Elt = struct type t = elt let compare = Stdlib.compare end
 module EltMap = Map.Make (Elt)
 
 type ce = AbsOrd.point * AbsOrd.point * AbsOrd.point
