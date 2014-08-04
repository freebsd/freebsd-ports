Make cowboy correctly parse target URI that has method in uppercase.

--- deps/cowboy/src/cowboy_protocol.erl.orig	2013-06-20 19:44:36.000000000 +0300
+++ deps/cowboy/src/cowboy_protocol.erl	2014-07-31 23:10:11.000000000 +0300
@@ -214,8 +214,12 @@
 	parse_version(Rest, State, Method, <<"*">>, <<>>);
 parse_uri(<< "http://", Rest/bits >>, State, Method) ->
 	parse_uri_skip_host(Rest, State, Method);
+parse_uri(<< "HTTP://", Rest/bits >>, State, Method) ->
+	parse_uri_skip_host(Rest, State, Method);
 parse_uri(<< "https://", Rest/bits >>, State, Method) ->
 	parse_uri_skip_host(Rest, State, Method);
+parse_uri(<< "HTTPS://", Rest/bits >>, State, Method) ->
+	parse_uri_skip_host(Rest, State, Method);
 parse_uri(Buffer, State, Method) ->
 	parse_uri_path(Buffer, State, Method, <<>>).
 
