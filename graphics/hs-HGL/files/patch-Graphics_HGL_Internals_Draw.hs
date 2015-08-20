--- Graphics/HGL/Internals/Draw.hs.orig	1991-05-09 14:40:52 UTC
+++ Graphics/HGL/Internals/Draw.hs
@@ -31,7 +31,7 @@ import Graphics.HGL.X11.Types(DC)
 import Graphics.HGL.Win32.Types(DC)
 #endif
 import qualified Graphics.HGL.Internals.Utilities as Utils (bracket, bracket_)
-import Control.Monad (liftM)
+import Control.Monad (liftM, ap)
 
 ----------------------------------------------------------------
 -- Graphics
@@ -61,6 +61,10 @@ instance Monad Draw where
 
 instance Functor Draw where fmap = liftM
 
+instance Applicative Draw where
+  pure  = return
+  (<*>) = ap
+
 -- | Wrap a drawing action in initialization and finalization actions.
 bracket
   :: Draw a		-- ^ a pre-operation, whose value is passed to the
