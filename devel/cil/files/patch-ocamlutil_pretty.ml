--- ocamlutil/pretty.ml.orig	2013-07-24 15:07:11 UTC
+++ ocamlutil/pretty.ml
@@ -725,31 +725,31 @@ let gprintf (finish : doc -> 'b)  
               invalid_arg ("dprintf: unimplemented format " 
 			   ^ (String.sub format i (j-i+1)));
 	    let j' = succ j in (* eat the d,i,x etc. *)
-	    let format_spec = "% " in
-	    String.set format_spec 1 (fget j'); (* format_spec = "%x", etc. *)
+	    let format_spec = Bytes.of_string "% " in
+	    Bytes.set format_spec 1 (fget j'); (* format_spec = "%x", etc. *)
             Obj.magic(fun n ->
               collect (dctext1 acc
-                         (Int64.format format_spec n))
+                         (Int64.format (Bytes.to_string format_spec) n))
                 (succ j'))
 	| 'l' ->
 	    if j != i + 1 then invalid_arg ("dprintf: unimplemented format " 
 					    ^ (String.sub format i (j-i+1)));
 	    let j' = succ j in (* eat the d,i,x etc. *)
-	    let format_spec = "% " in
-	    String.set format_spec 1 (fget j'); (* format_spec = "%x", etc. *)
+	    let format_spec = Bytes.of_string "% " in
+	    Bytes.set format_spec 1 (fget j'); (* format_spec = "%x", etc. *)
             Obj.magic(fun n ->
               collect (dctext1 acc
-                         (Int32.format format_spec n))
+                         (Int32.format (Bytes.to_string format_spec) n))
                 (succ j'))
 	| 'n' ->
 	    if j != i + 1 then invalid_arg ("dprintf: unimplemented format " 
 					    ^ (String.sub format i (j-i+1)));
 	    let j' = succ j in (* eat the d,i,x etc. *)
-	    let format_spec = "% " in
-	    String.set format_spec 1 (fget j'); (* format_spec = "%x", etc. *)
+	    let format_spec = Bytes.of_string "% " in
+	    Bytes.set format_spec 1 (fget j'); (* format_spec = "%x", etc. *)
             Obj.magic(fun n ->
               collect (dctext1 acc
-                         (Nativeint.format format_spec n))
+                         (Nativeint.format (Bytes.to_string format_spec) n))
                 (succ j'))
         | 'f' | 'e' | 'E' | 'g' | 'G' ->
             Obj.magic(fun f ->
