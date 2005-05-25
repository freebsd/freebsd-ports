--- libraries/base/Data/List.hs.orig	Tue May 24 23:25:06 2005
+++ libraries/base/Data/List.hs	Tue May 24 23:37:14 2005
@@ -144,7 +144,7 @@ import GHC.Show	( lines, words, unlines,
 import GHC.Base
 #endif
 
-infix 5 \\ 
+infix 5 \\ -- comment to fool cpp
 
 -- -----------------------------------------------------------------------------
 -- List functions
