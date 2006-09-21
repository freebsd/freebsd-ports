--- lib/IPC/Cmd.pm	Wed Sep  6 17:34:32 2006
+++ lib/IPC/Cmd.pm	Thu Sep 21 13:15:15 2006
@@ -260,8 +260,7 @@ sub _open3_run {
     ### child process. This stops us from having to pump input
     ### from ourselves to the childprocess. However, we will need
     ### to revive the FH afterwards, as IPC::Open3 closes it.
-    my $save_stdin;
-    open $save_stdin, "<&STDIN" or (
+    open IPC_CMD_SAVE_STDIN, "<&STDIN" or (
         warn(loc("Could not dup STDIN: %1",$!)),
         return
     );
@@ -317,7 +316,7 @@ sub _open3_run {
     
     ### restore STDIN after duping, or STDIN will be closed for
     ### this current perl process!
-    open STDIN, "<&", $save_stdin or (
+    open STDIN, "<& IPC_CMD_SAVE_STDIN" or (
         warn(loc("Could not restore STDIN: %1", $!)),
         return
     );        
