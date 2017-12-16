--- lib/ssl/src/tls_connection.erl.orig	2015-03-31 12:32:52.000000000 +0000
+++ lib/ssl/src/tls_connection.erl	2017-12-14 13:22:41.792681000 +0000
@@ -197,6 +197,7 @@
             ssl_connection:hello({common_client_hello, Type, ServerHelloExt, HashSign},
 				 State#state{connection_states  = ConnectionStates,
 					     negotiated_version = Version,
+					     client_hello_version = ClientVersion,
 					     session = Session,
 					     client_ecc = {EllipticCurves, EcPointFormats}}, ?MODULE);
         #alert{} = Alert ->
