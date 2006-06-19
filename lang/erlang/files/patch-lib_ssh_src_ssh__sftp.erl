
$FreeBSD$

--- lib/ssh/src/ssh_sftp.erl.orig
+++ lib/ssh/src/ssh_sftp.erl
@@ -283,8 +283,10 @@
 	    {stop, Error }
     end;
 init([Host,Port,Opts]) ->
+    SaveFlag = process_flag(trap_exit, true),
     case ssh_xfer:connect(Host, Port, Opts) of
 	{ok, Xf, RBuf} ->
+	    process_flag(trap_exit, SaveFlag),
 	    {ok, #state { req_id = 0, xf = Xf, rep_buf=RBuf }};
 	Error ->
 	    {stop, Error}
