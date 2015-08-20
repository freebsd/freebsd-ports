--- Data/ASN1/Parse.hs.orig	2012-08-28 06:24:31 UTC
+++ Data/ASN1/Parse.hs
@@ -25,7 +25,7 @@ import Control.Applicative ((<$>))
 
 -- | Parse ASN1 Monad
 newtype ParseASN1 a = P { runP :: ErrorT String (State [ASN1]) a }
-        deriving (Functor, Monad, MonadError String)
+        deriving (Functor, Applicative, Monad, MonadError String)
 
 -- | run the parse monad over a stream and returns the result and the remaining ASN1 Stream.
 runParseASN1State :: ParseASN1 a -> [ASN1] -> Either String (a,[ASN1])
