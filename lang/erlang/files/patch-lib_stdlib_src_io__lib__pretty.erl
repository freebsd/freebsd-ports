
$FreeBSD$

--- lib/stdlib/src/io_lib_pretty.erl.orig
+++ lib/stdlib/src/io_lib_pretty.erl
@@ -159,7 +159,9 @@
 %% Reuse the list created by io_lib:write_binary()...
 pp_binary([LT,LT,S,GT,GT], Col, Ll, Ind, LD) ->
     N = max(8, Ll - Col - LD),
-    [LT,LT,pp_binary(S, N, N, Ind),GT,GT].
+    [LT,LT,pp_binary(S, N, N, Ind),GT,GT];
+pp_binary(S, _Col, _Ll, _Ind, _LD) ->
+    S.
 
 pp_binary([BS, $, | S], N, N0, Ind) ->
     Len = length(BS) + 1,
