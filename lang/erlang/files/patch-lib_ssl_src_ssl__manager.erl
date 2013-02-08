
$FreeBSD$

--- lib/ssl/src/ssl_manager.erl.orig
+++ lib/ssl/src/ssl_manager.erl
@@ -145,7 +145,7 @@
     call({new_session_id, Port}).
 
 clean_cert_db(Ref, File) ->
-    erlang:send_after(?CLEAN_CERT_DB, self(), {clean_cert_db, Ref, File}).
+    erlang:send_after(?CLEAN_CERT_DB, get(ssl_manager), {clean_cert_db, Ref, File}).
 
 %%--------------------------------------------------------------------
 -spec register_session(inet:port_number(), #session{}) -> ok.
