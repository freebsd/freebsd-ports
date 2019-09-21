--- smlnj-lib/JSON/json-util.sml.orig	2017-04-29 15:39:27 UTC
+++ smlnj-lib/JSON/json-util.sml
@@ -133,7 +133,7 @@ structure JSONUtil : sig
 
     fun lookupField (v as J.OBJECT fields) = let
 	  fun find lab = (case List.find (fn (l, v) => (l = lab)) fields
-		 of NONE => raise FieldNotFound(v, concat["no definition for field \"", lab, "\""])
+		 of NONE => raise FieldNotFound(v, lab)
 		  | SOME(_, v) => v
 		(* end case *))
 	  in
@@ -197,7 +197,7 @@ structure JSONUtil : sig
     fun get (v, []) = v
       | get (v as J.OBJECT fields, SEL lab :: rest) =
 	  (case List.find (fn (l, v) => (l = lab)) fields
-	   of NONE => raise raise FieldNotFound(v, concat["no definition for field \"", lab, "\""])
+	   of NONE => raise FieldNotFound(v, lab)
 	    | SOME(_, v) => get (v, rest)
 	  (* end case *))
       | get (v, SEL _ :: _) = raise NotObject v
@@ -222,7 +222,7 @@ structure JSONUtil : sig
   (* follow a path into a JSON value while constructing a zipper *)
     fun unzip (v, []) = (ZNIL, v)
       | unzip (v as J.OBJECT fields, SEL lab :: rest) = let
-          fun find (_, []) = raise FieldNotFound(v, concat["no definition for field \"", lab, "\""])
+          fun find (_, []) = raise FieldNotFound(v, lab)
             | find (pre, (l, v)::flds) = if (l = lab)
                 then let
 		  val (zipper, v) = unzip (v, rest)
