
$FreeBSD$

--- lib/ssl/src/ssl_prim.erl.orig
+++ lib/ssl/src/ssl_prim.erl
@@ -107,7 +107,7 @@
 peername(St) when record(St, st), St#st.status =:= open  ->
     case ssl_server:peername_prim(ssl_server_prim, St#st.fd) of
 	{ok, {Address, Port}} ->
-	    {ok, At} = inet:getaddr(Address, inet),
+	    {ok, At} = inet_parse:ipv4_address(Address),
 	    {ok, {At, Port}};
 	Error ->
 	    Error
@@ -119,7 +119,7 @@
 sockname(St) when record(St, st), St#st.status =:= open  ->
     case ssl_server:sockname_prim(ssl_server_prim, St#st.fd) of
 	{ok, {Address, Port}} ->
-	    {ok, At} = inet:getaddr(Address, inet),
+	    {ok, At} = inet_parse:ipv4_address(Address),
 	    {ok, {At, Port}};
 	Error ->
 	    Error
