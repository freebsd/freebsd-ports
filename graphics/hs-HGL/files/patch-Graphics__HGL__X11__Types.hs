--- ./Graphics/HGL/X11/Types.hs.orig	2009-11-03 15:50:11.000000000 +0100
+++ ./Graphics/HGL/X11/Types.hs	2013-05-01 01:53:35.000000000 +0200
@@ -30,6 +30,7 @@
 import Control.Concurrent.MVar (MVar)
 import Data.Bits
 import Data.Word (Word8)
+import System.IO.Error
 
 ----------------------------------------------------------------
 -- Units
@@ -84,8 +85,7 @@
   (X.Color p _ _ _ _) <-
       X.allocColor display color_map (X.Color 0 r g b xcolor_flags)
   return p)
-     `catch` \ err -> 
-               print err >> return 0
+     `catchIOError` \err -> print err >> return 0
 --	       ioError (userError ("Error: " ++ show err
 --			      ++ "\nUnable to allocate colo[u]r " ++ show (r,g,b) 
 --			      ++ " - I'll bet you're running Netscape."))
