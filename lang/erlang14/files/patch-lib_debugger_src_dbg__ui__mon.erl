
$FreeBSD$

--- lib/debugger/src/dbg_ui_mon.erl.orig	Thu Sep  4 22:26:08 2003
+++ lib/debugger/src/dbg_ui_mon.erl	Thu Sep  4 22:26:51 2003
@@ -379,7 +379,7 @@
 
 %% Help Menu
 gui_cmd('Debugger', State) ->
-    HelpFile = filename:join([code:lib_dir(debugger),"doc","index.html"]),
+    HelpFile = filename:join([code:lib_dir(debugger),"doc","html","index.html"]),
     tool_utils:open_help(State#state.gs, HelpFile),
     State;
 
