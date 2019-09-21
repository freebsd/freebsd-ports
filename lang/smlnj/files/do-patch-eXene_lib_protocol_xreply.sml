--- eXene/lib/protocol/xreply.sml.orig	2006-03-03 03:33:16 UTC
+++ eXene/lib/protocol/xreply.sml
@@ -51,7 +51,7 @@ structure XReply =
       fun get32 (s, i) = Word32.fromLargeWord(PackWord32Big.subVec(s, i div 4))
       fun getSigned32 (s, i) =
         Int32.fromLarge(LargeWord.toLargeInt(PackWord32Big.subVecX(s, i div 4)))
-      fun getWord (s, i) = Word.fromLargeWord(get32(s, i))
+      fun getWord (s, i) = Word.fromLargeWord(PackWord32Big.subVec(s, i div 4))
       fun getInt (s, i) = LargeWord.toIntX(PackWord32Big.subVecX(s, i div 4))
 
       val w8vextract = Word8VectorSlice.vector o Word8VectorSlice.slice
