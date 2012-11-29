
$FreeBSD$

--- lib/ssl/src/ssl_connection.erl.orig
+++ lib/ssl/src/ssl_connection.erl
@@ -986,6 +986,10 @@
     gen_fsm:reply(RecvFrom, {error, timeout}),
     {next_state, StateName, State#state{start_or_recv_from = undefined}, get_timeout(State)};
 
+handle_info({cancel_start_or_recv, RecvFrom}, StateName, State) when connection =/= StateName->
+    gen_fsm:reply(RecvFrom, {error, timeout}),
+    {next_state, StateName, State#state{start_or_recv_from = undefined}, get_timeout(State)};
+
 handle_info({cancel_start_or_recv, _RecvFrom}, StateName, State) ->
     {next_state, StateName, State, get_timeout(State)};
 
