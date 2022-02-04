--- xstr_match.ml.orig	2002-07-07 11:27:16 UTC
+++ xstr_match.ml
@@ -137,12 +137,12 @@ let noword_set() =
     
 
 let set_as_string set =
-  let s = String.make 32 ' ' in
+  let s = Bytes.make 32 ' ' in
   for i = 0 to 15 do
     s.[i+i]   <- Char.chr (set.(i) land 0xff);
     s.[i+i+1] <- Char.chr (set.(i) lsr 8);
   done;
-  s
+  Bytes.to_string s
 ;;
 
 
@@ -592,7 +592,7 @@ let replace_matched_substrings ml rl fl s =
   let length = total_length 0 transformer in
   let target = String.create length in
   form_replacement_ltor target transformer length;
-  target, !n_repl
+  Bytes.to_string target, !n_repl
 ;;
   
 
