--- ./Graphics/HGL/Internals/Utilities.hs.orig	2009-11-03 15:50:11.000000000 +0100
+++ ./Graphics/HGL/Internals/Utilities.hs	2013-05-01 01:30:47.000000000 +0200
@@ -20,7 +20,7 @@
         modMVar, modMVar_
 	) where
 
-import qualified Control.Exception as E (bracket, try, IOException, tryJust, ioErrors)
+import qualified Control.Exception as E (bracket, try, IOException, tryJust)
 import Control.Concurrent( MVar, takeMVar, putMVar )
 
 bracket :: IO a -> (a -> IO b) -> (a -> IO c) -> IO c
@@ -32,15 +32,7 @@
 
 type Exception = E.IOException
 safeTry :: IO a -> IO (Either Exception a)
-
-#if __GLASGOW_HASKELL >= 610 
--- ghc-6.10
 safeTry = E.try
-#else
--- ghc 6.8 (and below?)
-safeTry = E.tryJust E.ioErrors
-#endif
-
 
 ----------------------------------------------------------------
 -- Utilities
