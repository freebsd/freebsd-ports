
$FreeBSD$

--- src/dialyzer_plt.erl.orig
+++ src/dialyzer_plt.erl
@@ -43,7 +43,7 @@
 
 from_dets(Name, Dets) ->
   Plt = new(Name),
-  {ok, D} = dets:open_file(Dets, []),
+  {ok, D} = dets:open_file(Dets, [{access, read}]),
   true = ets:from_dets(Plt, D),
   ok = dets:close(D),
   Plt.
@@ -59,7 +59,7 @@
   MD5 = compute_md5(),
   case filelib:is_file(?INIT_PLT) andalso dets:is_dets_file(?INIT_PLT) of
     true ->
-      case dets:open_file(?INIT_PLT, []) of
+      case dets:open_file(?INIT_PLT, [{access, read}]) of
 	{ok, Dets} ->
 	  Res =
 	    case dets:lookup(Dets, md5) of
