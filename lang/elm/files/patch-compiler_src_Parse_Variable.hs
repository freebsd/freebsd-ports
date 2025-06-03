--- compiler/src/Parse/Variable.hs.orig	2019-10-20 14:31:43 UTC
+++ compiler/src/Parse/Variable.hs
@@ -21,7 +21,7 @@ import Foreign.Ptr (Ptr, plusPtr)
 import qualified Data.Set as Set
 import Data.Word (Word8)
 import Foreign.Ptr (Ptr, plusPtr)
-import GHC.Exts (Char(C#), Int#, (+#), (-#), chr#, uncheckedIShiftL#, word2Int#)
+import GHC.Exts (Char(C#), Int#, (+#), (-#), chr#, uncheckedIShiftL#, word2Int#, word8ToWord#)
 import GHC.Word (Word8(W8#))
 
 import qualified AST.Source as Src
@@ -384,4 +384,4 @@ unpack (W8# word#) =
 
 unpack :: Word8 -> Int#
 unpack (W8# word#) =
-  word2Int# word#
+  word2Int# (word8ToWord# word#)
