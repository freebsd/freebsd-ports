--- glob.ml.orig	2006-02-23 06:34:35 UTC
+++ glob.ml
@@ -100,13 +100,13 @@ let rec optimize_pattern pat res =
 	let s = String.create 2 in
 	  s.[0] <- c2;
 	  s.[1] <- c1;
-	  optimize_pattern (String s :: cdr) res
+	  optimize_pattern (String (Bytes.unsafe_to_string s) :: cdr) res
     | String s :: Char c :: cdr ->
 	let len = String.length s in
 	let ns = String.create (len + 1) in
 	  ns.[0] <- c;
 	  String.blit s 0 ns 1 (String.length s);
-	  optimize_pattern (String ns :: cdr) res
+	  optimize_pattern (String (Bytes.unsafe_to_string ns) :: cdr) res
     | Star :: Star :: cdr -> optimize_pattern (Star :: cdr) res
     | cons :: cdr  -> optimize_pattern cdr (cons :: res)
 
@@ -245,7 +245,7 @@ let quote_str s =
     | c ->
         buf.[!pos] <- c; pos := !pos + 1
   done;
-  String.sub buf 0 !pos
+  Bytes.sub_string buf 0 !pos
 
 let rec conv_str buf pat =
   match pat with
