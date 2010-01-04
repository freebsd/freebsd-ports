--- Mueval/Interpreter.hs.orig	2009-12-26 10:51:26.000000000 +0000
+++ Mueval/Interpreter.hs	2009-12-26 10:52:08.000000000 +0000
@@ -120,9 +120,9 @@
 
 -- | Renders the input String including its exceptions using @exceptionMsg@
 render :: (Control.Monad.Trans.MonadIO m) =>
-          Int -> -- ^ max number of characters to include
-          String -> -- ^ input
-          m (String, Bool) -- ^ ( output, @True@ if we found an exception )
+          Int -- ^ max number of characters to include
+          -> String -- ^ input
+          -> m (String, Bool) -- ^ ( output, @True@ if we found an exception )
 render i xs =
     do (out,Any b) <- runWriterT $ render' i (toStream xs)
        return (out,b)
