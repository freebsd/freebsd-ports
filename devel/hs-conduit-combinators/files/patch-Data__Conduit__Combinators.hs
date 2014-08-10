--- ./Data/Conduit/Combinators.hs.orig	2014-07-26 20:08:37.000000000 +0200
+++ ./Data/Conduit/Combinators.hs	2014-07-29 14:03:36.000000000 +0200
@@ -204,6 +204,7 @@
 import qualified Data.Sequences              as Seq
 import           Data.Sequences.Lazy
 import qualified Data.Vector.Generic         as V
+import qualified Data.Text                   as T
 import qualified Data.Vector.Generic.Mutable as VM
 import           Data.Void                   (absurd)
 import qualified Filesystem                  as F
@@ -228,6 +229,8 @@
 import qualified System.PosixCompat.Files as PosixC
 import           Data.Primitive.MutVar       (MutVar, newMutVar, readMutVar,
                                               writeMutVar)
+import Data.Streaming.Text hiding (decodeUtf8)
+import qualified Data.Streaming.Text as DST
 
 #ifndef WINDOWS
 import qualified System.Posix.Directory as Dir
@@ -1646,7 +1649,47 @@
 --
 -- Since 1.0.0
 decodeUtf8Lenient :: MonadThrow m => Conduit ByteString m Text
-decodeUtf8Lenient = CT.decodeUtf8Lenient
+decodeUtf8Lenient =
+    decodeNew onFailure "UTF8-lenient" 0 DST.decodeUtf8
+  where
+    onFailure _consumed _bs t rest = do
+        unless (T.null t) (yield t)
+        case S.uncons rest of
+            Nothing -> return ()
+            Just (_, rest') -> do
+                unless (S.null rest') (leftover rest')
+                yield $ T.singleton '\xFFFD'
+        decodeUtf8Lenient
+
+decodeNew
+    :: Monad m
+    => (Int -> S.ByteString -> T.Text -> S.ByteString -> Conduit S.ByteString m T.Text)
+    -> t
+    -> Int
+    -> (S.ByteString -> DecodeResult)
+    -> Conduit S.ByteString m T.Text
+decodeNew onFailure name =
+    loop
+  where
+    loop consumed dec =
+        await >>= maybe finish go
+      where
+        finish =
+            case dec S.empty of
+                DecodeResultSuccess _ _ -> return ()
+                DecodeResultFailure t rest -> onFailure consumed S.empty t rest
+        {-# INLINE finish #-}
+
+        go bs | S.null bs = loop consumed dec
+        go bs =
+            case dec bs of
+                DecodeResultSuccess t dec' -> do
+                    let consumed' = consumed + S.length bs
+                        next = do
+                            unless (T.null t) (yield t)
+                            loop consumed' dec'
+                     in consumed' `seq` next
+                DecodeResultFailure t rest -> onFailure consumed bs t rest
 
 -- | Stream in the entirety of a single line.
 --
