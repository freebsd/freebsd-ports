--- iOExtras.ml.orig	2006-02-23 22:09:29 UTC
+++ iOExtras.ml
@@ -87,4 +87,4 @@ let snarf_file filename =
 	ofs := !ofs + bytes;
     done;
     close fd;
-    s
+    Bytes.unsafe_to_string s
