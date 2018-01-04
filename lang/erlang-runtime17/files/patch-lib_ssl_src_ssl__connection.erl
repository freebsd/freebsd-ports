--- lib/ssl/src/ssl_connection.erl.orig	2015-03-31 12:32:52.000000000 +0000
+++ lib/ssl/src/ssl_connection.erl	2017-12-14 13:13:46.570861000 +0000
@@ -1135,8 +1135,25 @@
     request_client_cert(State2, Connection).
 
 certify_client_key_exchange(#encrypted_premaster_secret{premaster_secret= EncPMS},
-			    #state{private_key = Key} = State, Connection) ->
-    PremasterSecret = ssl_handshake:premaster_secret(EncPMS, Key),
+			    #state{private_key = Key, client_hello_version = {Major, Minor} = Version } = State, Connection) ->
+
+    %% Countermeasure for Bleichenbacher attack always provide some kind of premaster secret
+    %% and fail handshake later.RFC 5246 section 7.4.7.1.
+    PremasterSecret =
+	try ssl_handshake:premaster_secret(EncPMS, Key) of
+	    Secret when erlang:byte_size(Secret) == ?NUM_OF_PREMASTERSECRET_BYTES ->
+		case Secret of
+		    <<?BYTE(Major), ?BYTE(Minor), _/binary>> -> %% Correct
+			Secret;
+		    <<?BYTE(_), ?BYTE(_), Rest/binary>> -> %% Version mismatch
+			<<?BYTE(Major), ?BYTE(Minor), Rest/binary>>
+		end;
+	    _ -> %% erlang:byte_size(Secret) =/= ?NUM_OF_PREMASTERSECRET_BYTES
+		make_premaster_secret(Version, rsa)
+	catch
+	    #alert{description = ?DECRYPT_ERROR} ->
+		make_premaster_secret(Version, rsa)
+	end,
     calculate_master_secret(PremasterSecret, State, Connection, certify, cipher);
 
 certify_client_key_exchange(#client_diffie_hellman_public{dh_public = ClientPublicDhKey},
