--- src/jwtf/src/jwtf_keystore.erl.orig	2021-03-31 15:23:39 UTC
+++ src/jwtf/src/jwtf_keystore.erl
@@ -140,13 +140,18 @@ get_from_config(Kty, KID) ->
     end.
 
 pem_decode(PEM) ->
-    BinPEM = iolist_to_binary(string:replace(PEM, "\\n", "\n", all)),
-    case public_key:pem_decode(BinPEM) of
-        [PEMEntry] ->
-            public_key:pem_entry_decode(PEMEntry);
-        [] ->
-            throw({bad_request, <<"Not a valid key">>})
-    end.
+    BinPEM = re:replace(PEM, "\\\\n", "\n", [global, {return, binary}]),
+    try
+        case public_key:pem_decode(BinPEM) of
+            [PEMEntry] ->
+                public_key:pem_entry_decode(PEMEntry);
+            _ ->
+                throw({bad_request, <<"Not a valid key">>})
+        end
+   catch
+       error:_ ->
+           throw({bad_request, <<"Not a valid key">>})
+   end.
 
 kty(<<"HS", _/binary>>) ->
     "hmac";
