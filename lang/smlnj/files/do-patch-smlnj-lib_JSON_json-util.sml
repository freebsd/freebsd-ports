--- smlnj-lib/JSON/json-util.sml.orig	2017-04-29 17:39:27.000000000 +0200
+++ smlnj-lib/JSON/json-util.sml	2017-10-04 00:40:39.574909000 +0200
@@ -133,7 +133,7 @@
 
     fun lookupField (v as J.OBJECT fields) = let
 	  fun find lab = (case List.find (fn (l, v) => (l = lab)) fields
-		 of NONE => raise FieldNotFound(v, concat["no definition for field \"", lab, "\""])
+		 of NONE => raise FieldNotFound(v, lab)
 		  | SOME(_, v) => v
 		(* end case *))
 	  in
@@ -197,7 +197,7 @@
     fun get (v, []) = v
       | get (v as J.OBJECT fields, SEL lab :: rest) =
 	  (case List.find (fn (l, v) => (l = lab)) fields
-	   of NONE => raise raise FieldNotFound(v, concat["no definition for field \"", lab, "\""])
+	   of NONE => raise FieldNotFound(v, lab)
 	    | SOME(_, v) => get (v, rest)
 	  (* end case *))
       | get (v, SEL _ :: _) = raise NotObject v
@@ -222,7 +222,7 @@
   (* follow a path into a JSON value while constructing a zipper *)
     fun unzip (v, []) = (ZNIL, v)
       | unzip (v as J.OBJECT fields, SEL lab :: rest) = let
-          fun find (_, []) = raise FieldNotFound(v, concat["no definition for field \"", lab, "\""])
+          fun find (_, []) = raise FieldNotFound(v, lab)
             | find (pre, (l, v)::flds) = if (l = lab)
                 then let
 		  val (zipper, v) = unzip (v, rest)
