--- ./Mueval/Interpreter.hs.orig	2011-01-11 21:24:11.000000000 +0100
+++ ./Mueval/Interpreter.hs	2011-03-13 14:28:39.132489232 +0100
@@ -120,7 +120,7 @@
 exceptionMsg = "*Exception: "
 
 -- | Renders the input String including its exceptions using @exceptionMsg@
-render :: (Control.Monad.Trans.MonadIO m)
+render :: (Functor m, Control.Monad.Trans.MonadIO m)
           => Int -- ^ max number of characters to include
           -> String -- ^ input
           -> m (String, Bool) -- ^ ( output, @True@ if we found an exception )
