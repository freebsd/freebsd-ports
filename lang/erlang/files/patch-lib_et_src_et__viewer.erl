
$FreeBSD$

--- lib/et/src/et_viewer.erl.orig	Sat Jul 24 15:02:18 2004
+++ lib/et/src/et_viewer.erl	Sat Jul 24 15:04:38 2004
@@ -982,8 +982,7 @@
     noreply(S).
 
 click_error(Click, S) ->
-    gs:config(S#state.canvas, beep),
-    io:format("~p: ignored: ~p~n", [?MODULE, Click]).
+    gs:config(S#state.canvas, beep).
 
 %%%----------------------------------------------------------------------
 %%% Clone viewer
