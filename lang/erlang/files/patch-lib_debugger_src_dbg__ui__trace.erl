
$FreeBSD$

--- lib/debugger/src/dbg_ui_trace.erl.orig	Thu Sep  4 22:26:12 2003
+++ lib/debugger/src/dbg_ui_trace.erl	Thu Sep  4 22:26:56 2003
@@ -352,7 +352,7 @@
 
 %% Help menu
 gui_cmd('Debugger', State) ->
-    HelpFile = filename:join([code:lib_dir(debugger),"doc","index.html"]),
+    HelpFile = filename:join([code:lib_dir(debugger),"doc","html","index.html"]),
     tool_utils:open_help(State#state.gs, HelpFile),
     State;
 
