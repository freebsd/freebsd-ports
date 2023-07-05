--- lib/ipaddr.ml.orig	2019-03-03 17:12:39 UTC
+++ lib/ipaddr.ml
@@ -69,9 +69,9 @@ let int_of_char c = match c with
 let char_A = int_of_char 'A'
 
 let int_of_char c = match c with
-  | '0'..'9' -> Pervasives.int_of_char c - char_0
-  | 'a'..'f' -> 10 + Pervasives.int_of_char c - char_a
-  | 'A'..'F' -> 10 + Pervasives.int_of_char c - char_A
+  | '0'..'9' -> Stdlib.int_of_char c - char_0
+  | 'a'..'f' -> 10 + Stdlib.int_of_char c - char_a
+  | 'A'..'F' -> 10 + Stdlib.int_of_char c - char_A
   | _ -> -1
 
 let bad_char i s =
@@ -258,7 +258,7 @@ module V4 = struct
 
     let compare (pre,sz) (pre',sz') =
       let c = compare pre pre' in
-      if c = 0 then Pervasives.compare sz sz' else c
+      if c = 0 then Stdlib.compare sz sz' else c
 
     let ip = make
 
@@ -706,7 +706,7 @@ module V6 = struct
 
     let compare (pre,sz) (pre',sz') =
       let c = compare pre pre' in
-      if c = 0 then Pervasives.compare sz sz' else c
+      if c = 0 then Stdlib.compare sz sz' else c
 
     let ip = make
 
