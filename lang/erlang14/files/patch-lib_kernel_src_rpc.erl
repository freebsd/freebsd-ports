
$FreeBSD$

--- lib/kernel/src/rpc.erl.orig
+++ lib/kernel/src/rpc.erl
@@ -495,16 +495,16 @@
 	      ReplyTo ! {self(), {promise_reply, R}}  %% self() is key
       end).
 
-yield(Key) when pid(Key) ->
-    {value, R} = do_yield(Key, infinite),
+yield(Key) when is_pid(Key) ->
+    {value,R} = do_yield(Key, infinity),
     R.
 
-nb_yield(Key, infinite) when pid(Key) ->
-    do_yield(Key, infinite);
-nb_yield(Key, Timeout) when pid(Key), integer(Timeout), Timeout >= 0 ->
+nb_yield(Key, infinity=Inf) when is_pid(Key) ->
+    do_yield(Key, Inf);
+nb_yield(Key, Timeout) when is_pid(Key), is_integer(Timeout), Timeout >= 0 ->
     do_yield(Key, Timeout).
 
-nb_yield(Key) when pid(Key) ->
+nb_yield(Key) when is_pid(Key) ->
     do_yield(Key, 0).
 
 do_yield(Key, Timeout) ->
