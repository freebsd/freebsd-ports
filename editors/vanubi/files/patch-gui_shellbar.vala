Add support of vte-2.91 instead of vte-2.90

--- gui/shellbar.vala.orig	2014-12-09 10:52:31 UTC
+++ gui/shellbar.vala
@@ -146,10 +146,10 @@ namespace Vanubi.UI {
 				}
 
 				Pid pid;
-				term.fork_command_full (PtyFlags.DEFAULT, workdir, {shell}, null, SpawnFlags.SEARCH_PATH, null, out pid);
+				term.spawn_sync (PtyFlags.DEFAULT, workdir, {shell}, null, SpawnFlags.SEARCH_PATH, null, out pid);
 				term.set_data ("pid", pid);
 				pty_cancellable = new Cancellable ();
-				read_sh.begin (term.pty_object.fd, pty_cancellable);
+				read_sh.begin (term.get_pty ().fd, pty_cancellable);
 
 				mouse_match (term, """^.+error:""");
 				mouse_match (term, """^.+warning:""");
