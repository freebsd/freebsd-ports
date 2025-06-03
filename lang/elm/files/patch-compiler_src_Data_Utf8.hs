--- compiler/src/Data/Utf8.hs.orig	2019-10-20 14:31:43 UTC
+++ compiler/src/Data/Utf8.hs
@@ -109,10 +109,10 @@ contains (W8# word#) (Utf8 ba#) =
   containsHelp word# ba# 0# (sizeofByteArray# ba#)
 
 
-containsHelp :: Word# -> ByteArray# -> Int# -> Int# -> Bool
+containsHelp :: Word8# -> ByteArray# -> Int# -> Int# -> Bool
 containsHelp word# ba# !offset# len# =
   if isTrue# (offset# <# len#) then
-    if isTrue# (eqWord# word# (indexWord8Array# ba# offset#))
+    if isTrue# (eqWord8# word# (indexWord8Array# ba# offset#))
       then True
       else containsHelp word# ba# (offset# +# 1#) len#
   else
@@ -145,7 +145,7 @@ startsWithChar isGood bytes@(Utf8 ba#) =
     False
   else
     let
-      !w# = indexWord8Array# ba# 0#
+      !w# = word8ToWord# (indexWord8Array# ba# 0#)
       !char
         | isTrue# (ltWord# w# 0xC0##) = C# (chr# (word2Int# w#))
         | isTrue# (ltWord# w# 0xE0##) = chr2 ba# 0# w#
@@ -164,7 +164,7 @@ endsWithWord8 (W8# w#) (Utf8 ba#) =
   let len# = sizeofByteArray# ba# in
   isTrue# (len# ># 0#)
   &&
-  isTrue# (eqWord# w# (indexWord8Array# ba# (len# -# 1#)))
+  isTrue# (eqWord8# w# (indexWord8Array# ba# (len# -# 1#)))
 
 
 
@@ -186,11 +186,11 @@ splitHelp str start offsets =
       unsafeSlice str start offset : splitHelp str (offset + 1) offsets
 
 
-findDividers :: Word# -> ByteArray# -> Int# -> Int# -> [Int] -> [Int]
+findDividers :: Word8# -> ByteArray# -> Int# -> Int# -> [Int] -> [Int]
 findDividers divider# ba# !offset# len# revOffsets =
   if isTrue# (offset# <# len#) then
     findDividers divider# ba# (offset# +# 1#) len# $
-      if isTrue# (eqWord# divider# (indexWord8Array# ba# offset#))
+      if isTrue# (eqWord8# divider# (indexWord8Array# ba# offset#))
       then I# offset# : revOffsets
       else revOffsets
   else
@@ -351,7 +351,7 @@ toCharsHelp ba# offset# len# =
     []
   else
     let
-      !w# = indexWord8Array# ba# offset#
+      !w# = word8ToWord# (indexWord8Array# ba# offset#)
       !(# char, width# #)
         | isTrue# (ltWord# w# 0xC0##) = (# C# (chr# (word2Int# w#)), 1# #)
         | isTrue# (ltWord# w# 0xE0##) = (# chr2 ba# offset# w#, 2# #)
@@ -368,7 +368,7 @@ chr2 ba# offset# firstWord# =
 chr2 ba# offset# firstWord# =
   let
     !i1# = word2Int# firstWord#
-    !i2# = word2Int# (indexWord8Array# ba# (offset# +# 1#))
+    !i2# = word2Int# (word8ToWord# (indexWord8Array# ba# (offset# +# 1#)))
     !c1# = uncheckedIShiftL# (i1# -# 0xC0#) 6#
     !c2# = i2# -# 0x80#
   in
@@ -380,8 +380,8 @@ chr3 ba# offset# firstWord# =
 chr3 ba# offset# firstWord# =
   let
     !i1# = word2Int# firstWord#
-    !i2# = word2Int# (indexWord8Array# ba# (offset# +# 1#))
-    !i3# = word2Int# (indexWord8Array# ba# (offset# +# 2#))
+    !i2# = word2Int# (word8ToWord# (indexWord8Array# ba# (offset# +# 1#)))
+    !i3# = word2Int# (word8ToWord# (indexWord8Array# ba# (offset# +# 2#)))
     !c1# = uncheckedIShiftL# (i1# -# 0xE0#) 12#
     !c2# = uncheckedIShiftL# (i2# -# 0x80#) 6#
     !c3# = i3# -# 0x80#
@@ -394,9 +394,9 @@ chr4 ba# offset# firstWord# =
 chr4 ba# offset# firstWord# =
   let
     !i1# = word2Int# firstWord#
-    !i2# = word2Int# (indexWord8Array# ba# (offset# +# 1#))
-    !i3# = word2Int# (indexWord8Array# ba# (offset# +# 2#))
-    !i4# = word2Int# (indexWord8Array# ba# (offset# +# 3#))
+    !i2# = word2Int# (word8ToWord# (indexWord8Array# ba# (offset# +# 1#)))
+    !i3# = word2Int# (word8ToWord# (indexWord8Array# ba# (offset# +# 2#)))
+    !i4# = word2Int# (word8ToWord# (indexWord8Array# ba# (offset# +# 3#)))
     !c1# = uncheckedIShiftL# (i1# -# 0xF0#) 18#
     !c2# = uncheckedIShiftL# (i2# -# 0x80#) 12#
     !c3# = uncheckedIShiftL# (i3# -# 0x80#) 6#
@@ -471,7 +471,7 @@ escape before@(W8# before#) after ptr name@(Utf8 ba#) 
 escape :: Word8 -> Word8 -> Ptr a -> Utf8 t -> Int -> Int -> Int -> IO ()
 escape before@(W8# before#) after ptr name@(Utf8 ba#) offset@(I# offset#) len@(I# len#) i@(I# i#) =
   if isTrue# (i# <# len#) then
-    if isTrue# (eqWord# before# (indexWord8Array# ba# (offset# +# i#)))
+    if isTrue# (eqWord8# before# (indexWord8Array# ba# (offset# +# i#)))
     then
       do  writeWordToPtr ptr i after
           escape before after ptr name offset len (i + 1)
