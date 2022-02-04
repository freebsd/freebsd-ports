--- xstr_search.ml.orig	1999-06-27 23:03:38 UTC
+++ xstr_search.ml
@@ -119,7 +119,7 @@ let rev_concat sep sl =
   in
 
   fill_in len sl;
-  t
+  Bytes.to_string t
 ;;
 
 
