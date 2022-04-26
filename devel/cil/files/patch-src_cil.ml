--- src/cil.ml.orig	2013-07-24 15:07:11 UTC
+++ src/cil.ml
@@ -5033,7 +5033,7 @@ let loadBinaryFile (filename : string) : file = 
 (* Take the name of a file and make a valid symbol name out of it. There are 
  * a few characters that are not valid in symbols *)
 let makeValidSymbolName (s: string) = 
-  let s = String.copy s in (* So that we can update in place *)
+  let b = Bytes.copy (Bytes.of_string s) in (* So that we can update in place *)
   let l = String.length s in
   for i = 0 to l - 1 do
     let c = String.get s i in
@@ -5043,9 +5043,9 @@ let makeValidSymbolName (s: string) = 
       | _ -> false
     in
     if isinvalid then 
-      String.set s i '_';
+      Bytes.set b i '_';
   done;
-  s
+  Bytes.to_string b
 
 let rec addOffset (toadd: offset) (off: offset) : offset =
   match off with
