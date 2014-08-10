--- ./src/Crypt/SHA256.hs.orig	2013-02-06 07:07:21.000000000 +0100
+++ ./src/Crypt/SHA256.hs	2014-07-13 18:41:00.000000000 +0200
@@ -20,6 +20,7 @@
 import Foreign.C.String ( withCString )
 import Data.ByteString.Unsafe (unsafeUseAsCStringLen)
 import qualified Data.ByteString as B
+import System.IO.Unsafe
 
 sha256sum :: B.ByteString -> String
 sha256sum p = unsafePerformIO $
