--- ocamlutil/errormsg.ml.orig	2013-07-24 15:07:11 UTC
+++ ocamlutil/errormsg.ml
@@ -211,16 +211,17 @@ let cleanFileName str = 
     if str <> "" && String.get str 0 = '"' (* '"' ( *) 
     then rem_quotes str else str in
   let l = String.length str1 in
+  let str1 = Bytes.of_string str1 in
   let rec loop (copyto: int) (i: int) = 
     if i >= l then 
-      String.sub str1 0 copyto
+      Bytes.to_string (Bytes.sub str1 0 copyto)
      else 
-       let c = String.get str1 i in
+       let c = Bytes.get str1 i in
        if c <> '\\' then begin
-          String.set str1 copyto c; loop (copyto + 1) (i + 1)
+          Bytes.set str1 copyto c; loop (copyto + 1) (i + 1)
        end else begin
-          String.set str1 copyto '/';
-          if i < l - 2 && String.get str1 (i + 1) = '\\' then
+          Bytes.set str1 copyto '/';
+          if i < l - 2 && Bytes.get str1 (i + 1) = '\\' then
               loop (copyto + 1) (i + 2)
           else 
               loop (copyto + 1) (i + 1)
