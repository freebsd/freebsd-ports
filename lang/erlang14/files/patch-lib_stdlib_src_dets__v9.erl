
$FreeBSD$

--- lib/stdlib/src/dets_v9.erl.orig	Mon Jul  7 14:17:44 2003
+++ lib/stdlib/src/dets_v9.erl	Fri Dec 26 14:58:33 2003
@@ -212,7 +212,6 @@
 -define(FREELIST_POS, 0).
 -define(CLOSED_PROPERLY_POS, 8).
 -define(D_POS, 20).
--define(NO_KEYS_POS, (?D_POS + 16)).
 
 %%% Dets file versions up to 8 are handled in dets_v8. This module
 %%% handles version 9, introduced in R8.
@@ -416,7 +415,7 @@
 		alloc_part(Head, SegZero, PartPos),
 	    {NewHead, InitSegment, [SegPointer]} =
                 alloc_seg(Head1, SegZero, SegNo, Part),
-	    {NewHead, InitSegment, [SegPointer, InitArrPart, ArrPartPointer]};
+	    {NewHead, InitSegment, [InitArrPart, SegPointer, ArrPartPointer]};
 	Part ->
             alloc_seg(Head, SegZero, SegNo, Part)
     end.
@@ -1222,7 +1221,7 @@
     %% Note that space for the array parts and the segments has
     %% already been allocated, but the segments have not been
     %% initialized on disk.
-    NoParts = no_parts(Head#head.m),
+    NoParts = no_parts(Head#head.next),
     %% All parts first, ensured by init_segments/6.
     Addr = ?BASE + NoParts * 4 * ?SEGPARTSZ,
     {Head, [{?FSCK_SEGMENT,Addr,Data,0} | L]};
@@ -1586,7 +1585,11 @@
     {FLW, FLSize} = free_lists_to_file(H1),
     FileSize = FreeListsPointer + FLSize + 4,
     ok = dets_utils:write(H, [FLW | <<FileSize:32>>]),
-    NoColls = case H1#head.no_collections of
+    FileHeader = file_header(H1, FreeListsPointer, ?CLOSED_PROPERLY),
+    dets_utils:pwrite(H1, [{0, FileHeader}]).
+
+file_header(Head, FreeListsPointer, ClosedProperly) ->
+    NoColls = case Head#head.no_collections of
 		  undefined -> [];
 		  NC -> NC
 	      end,
@@ -1594,8 +1597,7 @@
 		      NoColls, 
 		      lists:map(fun(X) -> {X,0} end, lists:seq(4,?MAXBUD-1))),
     CW = lists:map(fun({_LSz,N}) -> <<N:32>> end, L),
-    FileHeader = file_header(H1, FreeListsPointer, ?CLOSED_PROPERLY, CW),
-    dets_utils:pwrite(H1, [{0, FileHeader}]).
+    file_header(Head, FreeListsPointer, ClosedProperly, CW).
 
 file_header(Head, FreeListsPointer, ClosedProperly, NoColls) ->
     Cookie = ?MAGIC,
@@ -2356,17 +2358,18 @@
 update_no_keys(Head, Ws, DeltaObjects, DeltaKeys) ->
     NoKeys = Head#head.no_keys,
     NewNoKeys = NoKeys + DeltaKeys,
+    NewNoObject = Head#head.no_objects + DeltaObjects,
+    NewHead = Head#head{no_objects = NewNoObject, no_keys = NewNoKeys},
     NWs = 
 	if 
-	    NewNoKeys > Head#head.max_no_slots ->
+	    NewNoKeys > NewHead#head.max_no_slots ->
 		Ws;
 	    NoKeys div ?SEGSZP == NewNoKeys div ?SEGSZP ->
 		Ws;
 	    true ->
-		[{?NO_KEYS_POS, <<NewNoKeys:32>>} | Ws]
+                [{0, file_header(NewHead, 0, ?NOT_PROPERLY_CLOSED)} | Ws]
 	end,
-    NewNoObject = Head#head.no_objects + DeltaObjects,
-    {Head#head{no_objects = NewNoObject, no_keys = NewNoKeys}, NWs}.
+    {NewHead, NWs}.
 
 slot_position(S) ->
     SegNo = ?SLOT2SEG(S), % S div ?SEGSZP
