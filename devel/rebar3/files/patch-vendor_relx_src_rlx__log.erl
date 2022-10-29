--- vendor/relx/src/rlx_log.erl.orig	2022-10-29 06:26:35 UTC
+++ vendor/relx/src/rlx_log.erl
@@ -4,4 +4,4 @@
 
 -spec log(atom(), atom() | string() | binary(), [term()]) -> ok.
 log(_Level, Msg, Args) ->
-    io:format(Msg, Args).
+    io:format(Msg ++ "~n", Args).
