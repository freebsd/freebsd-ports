
$FreeBSD$

--- lib/et/src/et_gs_viewer.erl.orig	2010-03-11 16:26:59.000000000 +0800
+++ lib/et/src/et_gs_viewer.erl	2010-03-11 16:27:16.000000000 +0800
@@ -855,8 +855,7 @@ close_all_others(S) ->
     noreply(S).
 
 click_error(Click, S) ->
-    gs:config(S#state.canvas, beep),
-    io:format("~p: ignored: ~p~n", [?MODULE, Click]).
+    gs:config(S#state.canvas, beep).
 
 %%%----------------------------------------------------------------------
 %%% Clone viewer
