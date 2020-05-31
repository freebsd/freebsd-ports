--- src/ibrowse/src/ibrowse_http_client.erl.orig	2018-09-19 11:50:56 UTC
+++ src/ibrowse/src/ibrowse_http_client.erl
@@ -532,7 +532,7 @@ is_ipv6_host(Host) ->
         {ok, {_, _, _, _}} ->
             false;
         _  ->
-            case inet:gethostbyname(Host) of
+            case inet:gethostbyname(Host, inet6) of
                 {ok, #hostent{h_addrtype = inet6}} ->
                     true;
                 _ ->
