--- e3d/e3d_qbvh.erl.orig	2015-08-06 10:38:19 UTC
+++ e3d/e3d_qbvh.erl
@@ -40,6 +40,7 @@
 
 -define(F32, 32/float-native).
 -define(I32, 32/signed-native).
+-define(U32, 32/unsigned-native).
 -define(QNODE_SZ, ((24+4)*4)).
 -define(QTRI_SZ,  ((12*3+4)*4)).
 
@@ -118,8 +119,8 @@ convert_to_image(W, <<BBs:(24*4)/binary,
 convert_to_image(_, <<>>, Acc) -> Acc.
 
 convert_children(4, _W, Qns, Acc) ->  {Qns, Acc};
-convert_children(J, W, <<16#ffffffff:?I32, Qns/binary>>, Acc) ->  %% EMPTY
-    convert_children(J+1, W, Qns, <<Acc/binary, 16#ffffffff:?I32>>);
+convert_children(J, W, <<16#ffffffff:?U32, Qns/binary>>, Acc) ->  %% EMPTY
+    convert_children(J+1, W, Qns, <<Acc/binary, 16#ffffffff:?U32>>);
 convert_children(J, W, <<C0:?I32, Qns/binary>>, Acc) when C0 < 0 -> %% IS_LEAF
     Count = first_quad(C0) * 10,
     X = (Count rem W) div 10, %% "div 10" in order to not waste bits
