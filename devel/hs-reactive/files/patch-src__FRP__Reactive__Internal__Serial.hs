--- ./src/FRP/Reactive/Internal/Serial.hs.orig	2010-07-28 18:48:55.000000000 +0200
+++ ./src/FRP/Reactive/Internal/Serial.hs	2011-07-16 10:54:01.000000000 +0200
@@ -1,4 +1,4 @@
-{-# LANGUAGE Rank2Types, ImpredicativeTypes #-}
+{-# LANGUAGE Rank2Types #-}
 -- We need ImpredicativeTypes, but GHC 6.8 doesn't think it
 -- has them.  The cabal file configures this in a compiler-dependent
 -- way.
@@ -24,7 +24,7 @@
 import Control.Exception (bracket_)
 
 -- | Serializer.  Turns actions into equivalent but serialized actions
-type Serial = forall a. IO a -> IO a
+newtype Serial = Serial { unSerial :: forall a. IO a -> IO a }
 
 -- | Make a locking serializer
 makeSerial :: IO Serial
@@ -32,4 +32,4 @@
 
 -- | Make a locking serializer with a given lock
 locking :: MVar () -> Serial
-locking lock = bracket_ (putMVar lock ()) (takeMVar lock)
+locking lock = Serial $ bracket_ (putMVar lock ()) (takeMVar lock)
