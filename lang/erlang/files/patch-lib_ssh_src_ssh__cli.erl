
$FreeBSD$

--- lib/ssh/src/ssh_cli.erl.orig
+++ lib/ssh/src/ssh_cli.erl
@@ -161,17 +161,12 @@
 handle_info({ssh_cm, _CM,
 	     {window_change, _Channel, Width, Height, PixWidth, PixHeight}},
 	    State) ->
-    erlang:display(?LINE),
     #state{buf = Buf, pty = Pty, cm = CM, channel = Channel} = State,
-    erlang:display(?LINE),
     NewPty = Pty#ssh_pty{width = Width, height = Height,
 			 pixel_width = PixWidth,
 			 pixel_height = PixHeight},
-    erlang:display(?LINE),
     {Chars, NewBuf} = io_request({window_change, Pty}, Buf, NewPty),
-    erlang:display(?LINE),
     write_chars(CM, Channel, Chars),
-    erlang:display(?LINE),
     {noreply, State#state{pty = NewPty, buf = NewBuf}};
 handle_info({Group, Req}, State) when Group==State#state.group ->
     ?dbg(?DBG_IO_REQUEST, "io_request: ~w\n", [Req]),
