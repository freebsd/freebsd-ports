
$FreeBSD$

--- src/dialyzer_gui.erl.orig
+++ src/dialyzer_gui.erl
@@ -489,8 +489,8 @@
     {'EXIT', BackendPid, Reason} when Reason /= normal ->
       error(State, Reason),
       gui_loop(State);
-    Other ->
-      io:format("Received ~p\n", [Other]),
+    _Other ->
+      %% io:format("Received ~p\n", [Other]),
       gui_loop(State)
   end.
 
@@ -1019,7 +1019,7 @@
   ReAnalyze = 
     case filelib:is_file(Plt) of
       true ->
-	case dets:open_file(Plt) of
+	case dets:open_file(Plt,[{access,read}]) of
 	  {ok, Dets} ->
 	    Res =
 	      case dets:lookup(Dets, md5) of
