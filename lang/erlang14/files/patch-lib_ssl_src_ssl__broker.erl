
$FreeBSD$

--- lib/ssl/src/ssl_broker.erl.orig	Thu Mar 11 17:58:12 2004
+++ lib/ssl/src/ssl_broker.erl	Thu Mar 11 18:00:07 2004
@@ -330,6 +330,8 @@
 	    case gen_tcp:recv(St#st.proxysock, Length, Timeout) of
 		{ok, Data} ->
 		    {reply, {ok, Data}, St};
+		{error, timeout} ->
+		    {reply, {error, timeout}, St};
 		{error, Reason} ->
 		    {reply, {error, Reason}, St#st{status = closing}}
 	    end
