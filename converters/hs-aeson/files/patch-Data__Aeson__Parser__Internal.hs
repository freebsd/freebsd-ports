--- ./Data/Aeson/Parser/Internal.hs.orig	2014-05-16 17:43:52.000000000 +0200
+++ ./Data/Aeson/Parser/Internal.hs	2014-07-12 19:54:00.000000000 +0200
@@ -41,25 +41,29 @@
   (Builder, byteString, toLazyByteString, charUtf8, word8)
 #endif
 
-import Control.Applicative ((*>), (<$>), (<*), liftA2, pure)
+import Control.Applicative ((*>), (<$>), (<*), (<|>), liftA2, pure)
+import Control.Monad (when, void)
 import Data.Aeson.Types (Result(..), Value(..))
-import Data.Attoparsec.Char8 (Parser, char, endOfInput, scientific,
-                              skipSpace, string)
+import Data.Attoparsec.Char8 (Parser, char, endOfInput, isDigit_w8,
+                              skipSpace, string, decimal, signed)
 import Data.Bits ((.|.), shiftL)
 import Data.ByteString (ByteString)
 import Data.Char (chr)
 import Data.Monoid (mappend, mempty)
+import Data.Scientific (Scientific)
 import Data.Text (Text)
 import Data.Text.Encoding (decodeUtf8')
 import Data.Vector as Vector (Vector, fromList)
 import Data.Word (Word8)
 import qualified Data.Attoparsec as A
+import qualified Data.Attoparsec.ByteString as I
 import qualified Data.Attoparsec.Lazy as L
 import qualified Data.Attoparsec.Zepto as Z
 import qualified Data.ByteString as B
 import qualified Data.ByteString.Lazy as L
 import qualified Data.ByteString.Unsafe as B
 import qualified Data.HashMap.Strict as H
+import qualified Data.Scientific as Sci
 
 #define BACKSLASH 92
 #define CLOSE_CURLY 125
@@ -356,3 +360,40 @@
 #else
 peekWord8' = maybe (fail "not enough bytes") return =<< A.peekWord8
 #endif
+
+scientific :: A.Parser Scientific
+scientific = scientifically id
+
+-- A strict pair
+data SP = SP !Integer {-# UNPACK #-}!Int
+
+{-# INLINE scientifically #-}
+scientifically :: (Scientific -> a) -> Parser a
+scientifically h = do
+  let minus = 45
+      plus  = 43
+  sign <- peekWord8'
+  let !positive = sign == plus || sign /= minus
+  when (sign == plus || sign == minus) $
+    void $ I.anyWord8
+
+  n <- decimal
+
+  let f fracDigits = SP (B.foldl' step n fracDigits)
+                        (negate $ B.length fracDigits)
+      step a w = a * 10 + fromIntegral (w - 48)
+
+  dotty <- I.peekWord8
+  -- '.' -> ascii 46
+  SP c e <- case dotty of
+              Just 46 -> I.anyWord8 *> (f <$> I.takeWhile isDigit_w8)
+              _       -> pure (SP n 0)
+
+  let !signedCoeff | positive  =  c
+                   | otherwise = -c
+
+  let littleE = 101
+      bigE    = 69
+  (I.satisfy (\ex -> ex == littleE || ex == bigE) *>
+      fmap (h . Sci.scientific signedCoeff . (e +)) (signed decimal)) <|>
+    return (h $ Sci.scientific signedCoeff    e)
