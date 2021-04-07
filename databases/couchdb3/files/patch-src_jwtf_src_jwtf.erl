--- src/jwtf/src/jwtf.erl.orig	2021-03-31 15:23:39 UTC
+++ src/jwtf/src/jwtf.erl
@@ -188,8 +188,7 @@ validate_alg(Props, Checks) ->
     end.
 
 
-%% Not all these fields have to be present, but if they _are_ present
-%% they must be valid.
+%% Only validate required checks.
 validate_payload(Props, Checks) ->
     validate_iss(Props, Checks),
     validate_iat(Props, Checks),
@@ -202,7 +201,7 @@ validate_iss(Props, Checks) ->
     ActualISS = prop(<<"iss">>, Props),
 
     case {ExpectedISS, ActualISS} of
-        {undefined, undefined} ->
+        {undefined, _} -> % ignore unrequired check
             ok;
         {ISS, undefined} when ISS /= undefined ->
             throw({bad_request, <<"Missing iss claim">>});
@@ -218,11 +217,11 @@ validate_iat(Props, Checks) ->
     IAT = prop(<<"iat">>, Props),
 
     case {Required, IAT} of
-        {undefined, undefined} ->
+        {undefined, _} -> % ignore unrequired check
             ok;
         {true, undefined} ->
             throw({bad_request, <<"Missing iat claim">>});
-        {_, IAT} when is_integer(IAT) ->
+        {true, IAT} when is_integer(IAT) ->
             ok;
         {true, _} ->
             throw({bad_request, <<"Invalid iat claim">>})
@@ -234,12 +233,12 @@ validate_nbf(Props, Checks) ->
     NBF = prop(<<"nbf">>, Props),
 
     case {Required, NBF} of
-        {undefined, undefined} ->
+        {undefined, _} -> % ignore unrequired check
             ok;
         {true, undefined} ->
             throw({bad_request, <<"Missing nbf claim">>});
-        {_, IAT} ->
-            assert_past(<<"nbf">>, IAT)
+        {true, NBF} ->
+            assert_past(<<"nbf">>, NBF)
     end.
 
 
@@ -248,11 +247,11 @@ validate_exp(Props, Checks) ->
     EXP = prop(<<"exp">>, Props),
 
     case {Required, EXP} of
-        {undefined, undefined} ->
+        {undefined, _} -> % ignore unrequired check
             ok;
         {true, undefined} ->
             throw({bad_request, <<"Missing exp claim">>});
-        {_, EXP} ->
+        {true, EXP} ->
             assert_future(<<"exp">>, EXP)
     end.
 
@@ -351,3 +350,20 @@ now_seconds() ->
 
 prop(Prop, Props) ->
     proplists:get_value(Prop, Props).
+
+
+-ifdef(TEST).
+-include_lib("eunit/include/eunit.hrl").
+
+validate_payload_ignore_unchecked_props_test() ->
+    ?assertEqual(ok, validate_payload(_Props = [], _Checks = [])),
+    BogusProps = [
+        {iss, bogus},
+        {iat, bogus},
+        {nbf, bogus},
+        {exp, bogus}
+    ],
+    ?assertEqual(ok, validate_payload(BogusProps, _Checks = [])),
+    ok.
+
+-endif.
