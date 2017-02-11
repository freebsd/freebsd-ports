--- src/rlx_prv_assembler.erl.orig	2016-12-27 16:21:42 UTC
+++ src/rlx_prv_assembler.erl
@@ -121,7 +121,10 @@ format_error({start_clean_script_generat
      rlx_util:indent(2), Module:format_error(Errors)];
 format_error({strip_release, Reason}) ->
     io_lib:format("Stripping debug info from release beam files failed becuase ~s",
-                  [beam_lib:format_error(Reason)]).
+                  [beam_lib:format_error(Reason)]);
+format_error({rewrite_app_file, AppFile, Error}) ->
+    io_lib:format("Unable to rewrite .app file ~s due to ~p",
+                  [AppFile, Error]).
 
 %%%===================================================================
 %%% Internal Functions
@@ -255,13 +258,16 @@ rewrite_app_file(State, App, TargetDir) 
                                  ,AppData2
                                  ,{modules, OldModules -- ExcludedModules})
         end,
-    Spec = io_lib:format("~p.\n", [{application, AppName, AppData3}]),
-    write_file_if_contents_differ(AppFile, Spec).
+    Spec = [{application, AppName, AppData3}],
+    case write_file_if_contents_differ(AppFile, Spec) of
+        ok -> ok;
+        Error -> ?RLX_ERROR({rewrite_app_file, AppFile, Error})
+    end.
 
-write_file_if_contents_differ(Filename, Bytes) ->
-    ToWrite = iolist_to_binary(Bytes),
-    case file:read_file(Filename) of
-        {ok, ToWrite} ->
+write_file_if_contents_differ(Filename, Spec) ->
+    ToWrite = io_lib:format("~p.\n", Spec),
+    case file:consult(Filename) of
+        {ok, Spec} ->
             ok;
         {ok,  _} ->
             file:write_file(Filename, ToWrite);
