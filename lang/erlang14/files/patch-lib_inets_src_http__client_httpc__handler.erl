
$FreeBSD$

--- lib/inets/src/http_client/httpc_handler.erl.orig
+++ lib/inets/src/http_client/httpc_handler.erl
@@ -186,7 +186,7 @@
             case State#state.request of
                 #request{} -> %% Old request no yet finished
 		    %% Make sure to use the new value of timers in state
-		    Timers = NewState#state.timers,
+		    NewTimers = NewState#state.timers,
                     NewPipeline = queue:in(Request, State#state.pipeline),
 		    NewSession = 
 			Session#tcp_session{pipeline_length = 
@@ -196,7 +196,7 @@
 		    httpc_manager:insert_session(NewSession),
                     {reply, ok, State#state{pipeline = NewPipeline,
 					    session = NewSession,
-					    timers = Timers}};
+					    timers = NewTimers}};
 		undefined ->
 		    %% Note: tcp-message reciving has already been
 		    %% activated by handle_pipeline/2. Also
