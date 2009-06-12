
$FreeBSD$

--- lib/compiler/src/beam_utils.erl.orig
+++ lib/compiler/src/beam_utils.erl
@@ -650,8 +650,8 @@
     Regs2 = x_live([Src1,Src2], Regs1),
     Regs = live_join_label(Fail, D, Regs2),
     live_opt(Is, Regs, D, [I|Acc]);
-live_opt([{bs_append,Fail,Src1,_,_,_,Src2,_,Dst}=I|Is], Regs0, D, Acc) ->
-    Regs1 = x_live([Src1,Src2], x_dead([Dst], Regs0)),
+live_opt([{bs_append,Fail,Src1,_,Live,_,Src2,_,Dst}=I|Is], _Regs0, D, Acc) ->
+    Regs1 = x_dead([Dst], x_live([Src1,Src2], live_call(Live))),
     Regs = live_join_label(Fail, D, Regs1),
     live_opt(Is, Regs, D, [I|Acc]);
 live_opt([{bs_private_append,Fail,Src1,_,Src2,_,Dst}=I|Is], Regs0, D, Acc) ->
