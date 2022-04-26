--- src/formatlex.mll.orig	2013-07-24 15:07:11 UTC
+++ src/formatlex.mll
@@ -145,11 +145,11 @@ let scan_oct_escape str =
  * We convert L"Hi" to "H\000i\000" *)
 let wbtowc wstr =
   let len = String.length wstr in 
-  let dest = String.make (len * 2) '\000' in 
+  let dest = Bytes.make (len * 2) '\000' in 
   for i = 0 to len-1 do 
-    dest.[i*2] <- wstr.[i] ;
+    Bytes.set dest (i*2) (String.get wstr i)
   done ;
-  dest
+  Bytes.to_string dest
 
 (* This function converst the "Hi" in L"Hi" to { L'H', L'i', L'\0' } *)
 let wstr_to_warray wstr =
