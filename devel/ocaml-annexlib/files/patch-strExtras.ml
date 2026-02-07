--- strExtras.ml.orig	2006-02-23 06:34:35 UTC
+++ strExtras.ml
@@ -144,7 +144,7 @@ let map f str =
     for n = 0 to len - 1 do
       String.unsafe_set nstr n (f (String.unsafe_get str n))
     done;
-    nstr
+    Bytes.unsafe_to_string nstr
 
 let mapi f str =
   let len = String.length str in
@@ -152,18 +152,18 @@ let mapi f str =
     for n = 0 to len - 1 do
       String.unsafe_set nstr n (f (String.unsafe_get str n) n)
     done;
-    nstr
+    Bytes.unsafe_to_string nstr
       
 let map_inplace f str =
-  let len = String.length str in
+  let len = Bytes.length str in
     for n = 0 to len - 1 do
-      String.unsafe_set str n (f (String.unsafe_get str n))
+      Bytes.unsafe_set str n (f (Bytes.unsafe_get str n))
     done
 
 let mapi_inplace f str =
-  let len = String.length str in
+  let len = Bytes.length str in
     for n = 0 to len - 1 do
-      String.unsafe_set str n (f (String.unsafe_get str n) n)
+      Bytes.unsafe_set str n (f (Bytes.unsafe_get str n) n)
     done
 
 let iteri f str =
@@ -194,16 +194,16 @@ let lowercase = map CharExtras.to_lower
 let capitalize str = 
   if String.length str = 0 then ""
   else
-    let nstr = String.copy str in
-      String.unsafe_set nstr 0 (CharExtras.to_upper (String.unsafe_get nstr 0));
-      nstr
+    let nstr = Bytes.of_string str in
+      Bytes.unsafe_set nstr 0 (CharExtras.to_upper (Bytes.unsafe_get nstr 0));
+      Bytes.unsafe_to_string nstr
 
 let uncapitalize str = 
   if String.length str = 0 then ""
   else
-    let nstr = String.copy str in
-      String.unsafe_set nstr 0 (CharExtras.to_lower (String.unsafe_get nstr 0));
-      nstr
+    let nstr = Bytes.of_string str in
+      Bytes.unsafe_set nstr 0 (CharExtras.to_lower (Bytes.unsafe_get nstr 0));
+      Bytes.unsafe_to_string nstr
 
 
 let startletter = Pcre.regexp "\\b\\w"
@@ -281,28 +281,28 @@ let center ?(pad=' ') ?(trunc=false) src width =
 	String.copy src
     end else 
       let space = (width - len) / 2 in
-      let centered = String.make width pad in
+      let centered = Bytes.make width pad in
 	String.blit src 0 centered space len;
-	centered
+	Bytes.unsafe_to_string centered
 
 let rev s =
-  let str = String.copy s in
+  let str = Bytes.of_string s in
   let n = ref 0
-  and p = ref ((String.length str) - 1) in
+  and p = ref ((Bytes.length str) - 1) in
     while !n < !p do
-      let tmp = String.unsafe_get str !n in
-	String.unsafe_set str !n (String.unsafe_get str !p);
+      let tmp = Bytes.unsafe_get str !n in
+	Bytes.unsafe_set str !n (Bytes.unsafe_get str !p);
 	String.unsafe_set str !p tmp;
 	incr n;
 	decr p;
     done;
-    str
+    Bytes.unsafe_to_string str
 
 let implode lst =
   let str = String.create (List.length lst) in
   let pos = ref 0 in
     List.iter (fun c -> str.[!pos] <- c; incr pos) lst;
-    str
+    Bytes.unsafe_to_string str
 
 let explode str =
   let res = ref [] in
@@ -332,9 +332,9 @@ let ljust ?(pad=' ') ?(trunc=false) str n =
       else 
 	String.copy str
     end else 
-      let newstr = String.make n pad in
+      let newstr = Bytes.make n pad in
 	String.blit str 0 newstr 0 len;
-	newstr
+	Bytes.unsafe_to_string newstr
 
 let rjust ?(pad=' ') ?(trunc=false) str  n =
   let len = String.length str in
@@ -344,9 +344,9 @@ let rjust ?(pad=' ') ?(trunc=false) str  n =
       else 
 	String.copy str
     end else 
-      let newstr = String.make n pad in
+      let newstr = Bytes.make n pad in
 	String.blit str 0 newstr (n - len) len;
-	newstr
+	Bytes.unsafe_to_string newstr
 
 let subpos str start stop =
   let len = stop - start + 1 in
@@ -376,7 +376,7 @@ let repeat str times =
     for n = 0 to times - 1 do
       String.unsafe_blit str 0 newstr (n * len) len
     done;
-    newstr
+    Bytes.unsafe_to_string newstr
 
 external collate: string -> string -> int = "stew_strcoll"
 
@@ -463,7 +463,7 @@ let replace str old rep =
 let of_array arr = 
   let str = String.create (Array.length arr) in
     Array.iteri (fun i c -> str.[i] <- c) arr;
-    str
+    Bytes.unsafe_to_string str
 
 let to_array str = Array.init (String.length str) (function i -> str.[i])
 
