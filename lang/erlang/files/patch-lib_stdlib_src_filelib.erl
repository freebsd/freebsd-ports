
$FreeBSD$

--- lib/stdlib/src/filelib.erl.orig	Thu Mar 11 21:05:33 2004
+++ lib/stdlib/src/filelib.erl	Thu Mar 11 21:06:40 2004
@@ -84,7 +84,10 @@
 		false ->
 		    fold_files(T, Dir, RegExp, Recursive, Fun, Acc0)
 	    end
-    end.
+    end;
+
+fold_files([], _, _, _, _, Acc) ->
+    Acc.
 
 last_modified(File) ->
     case file:read_file_info(File) of
