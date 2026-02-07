--- compiler/src/Data/Name.hs.orig	2019-10-20 14:31:43 UTC
+++ compiler/src/Data/Name.hs
@@ -241,7 +241,7 @@ fromTypeVariable name@(Utf8.Utf8 ba#) index =
   else
     let
       len# = sizeofByteArray# ba#
-      end# = indexWord8Array# ba# (len# -# 1#)
+      end# = word8ToWord# (indexWord8Array# ba# (len# -# 1#))
     in
     if isTrue# (leWord# 0x30## end#) && isTrue# (leWord# end# 0x39##) then
       runST
@@ -316,11 +316,11 @@ fromManyNames names =
         ST $ \s ->
           case newByteArray# (len# +# 3#) s of
             (# s, mba# #) ->
-              case writeWord8Array# mba# 0# 0x5F## {-_-} s of
+              case writeWord8Array# mba# 0# (wordToWord8# 0x5F##) {-_-} s of
                 s ->
-                  case writeWord8Array# mba# 1# 0x4D## {-M-} s of
+                  case writeWord8Array# mba# 1# (wordToWord8# 0x4D##) {-M-} s of
                     s ->
-                      case writeWord8Array# mba# 2# 0x24## {-$-} s of
+                      case writeWord8Array# mba# 2# (wordToWord8# 0x24##) {-$-} s of
                         s ->
                           case copyByteArray# ba# 0# mba# 3# len# s of
                             s ->
