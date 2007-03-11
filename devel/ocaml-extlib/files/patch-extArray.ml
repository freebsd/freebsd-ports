--- extArray.ml	2005/11/25 10:22:10	1.8
+++ extArray.ml	2006/10/11 16:24:42	1.9
@@ -162,4 +162,11 @@
        | Some x -> x
        | None -> assert false)
 
+let iter2 f a1 a2 =
+     if Array.length a1 <> Array.length a2
+     then raise (Invalid_argument "Array.iter2");
+     for i = 0 to Array.length a1 - 1 do
+       f a1.(i) a2.(i);
+     done;;
+
 end
