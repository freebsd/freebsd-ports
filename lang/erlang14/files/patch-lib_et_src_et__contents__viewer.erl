
$FreeBSD$

--- lib/et/src/et_contents_viewer.erl.orig	Sat Jul 24 15:04:01 2004
+++ lib/et/src/et_contents_viewer.erl	Sat Jul 24 15:04:31 2004
@@ -346,7 +346,6 @@
         'Caps_Lock' ->
             {noreply, S};
         _ ->
-            io:format("~p: ignored: ~p~n", [?MODULE, KeySym]),
             {noreply, S}
     end;
 handle_info({gs, _Obj, configure, [], [W, H | _]}, S) ->
