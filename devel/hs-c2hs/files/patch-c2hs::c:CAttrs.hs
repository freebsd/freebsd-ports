--- c2hs/c/CAttrs.hs.orig	Mon Feb 12 07:34:38 2001
+++ c2hs/c/CAttrs.hs	Sun Feb 15 14:02:03 2004
@@ -144,7 +144,7 @@
 --
 leaveObjRangeC    :: AttrC -> AttrC
 leaveObjRangeC ac  = ac {
-		       defObjsAC = fst . leaveRange . defObjsAC $ ac,
+		       defObjsAC = fst . leaveRange . defObjsAC $ ac
 		     }
 
 -- add another definitions to the object name space (EXPORTED)
