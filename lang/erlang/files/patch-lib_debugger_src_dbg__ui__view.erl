
$FreeBSD$

--- lib/debugger/src/dbg_ui_view.erl.orig	Thu Sep  4 22:26:16 2003
+++ lib/debugger/src/dbg_ui_view.erl	Thu Sep  4 22:29:05 2003
@@ -165,7 +165,7 @@
 
 %% Help menu
 gui_cmd('Debugger', State) ->
-    HelpFile = filename:join([code:lib_dir(debugger),"doc","index.html"]),
+    HelpFile = filename:join([code:lib_dir(debugger),"doc","html","index.html"]),
     tool_utils:open_help(State#state.gs, HelpFile),
     State.
 
