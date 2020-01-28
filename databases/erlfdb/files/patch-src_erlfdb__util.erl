--- src/erlfdb_util.erl.orig	2020-01-20 22:27:20 UTC
+++ src/erlfdb_util.erl
@@ -177,6 +177,7 @@ find_fdbserver_bin(Options) ->
         undefined ->
             [
                 <<"/usr/sbin/fdbserver">>,
+                <<"/usr/local/bin/fdbserver">>,
                 <<"/usr/local/sbin/fdbserver">>,
                 <<"/usr/local/libexec/fdbserver">>
             ];
