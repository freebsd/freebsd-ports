
$FreeBSD$

--- lib/runtime_tools/src/observer_backend.erl.orig
+++ lib/runtime_tools/src/observer_backend.erl
@@ -83,7 +83,7 @@
 	       ets -> ets:info(Table, size);
 	       mnesia -> mnesia:table_info(Table, size)
 	   end,
-    case Size > 0 of
+    case Size =/= undefined andalso Size > 0 of
 	false ->
 	    Parent ! {self(), '$end_of_table'},
 	    normal;
