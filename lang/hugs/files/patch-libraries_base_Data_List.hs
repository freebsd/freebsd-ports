--- ../fptools/libraries/base/Data/List.hs.orig	Wed Nov 26 10:55:24 2003
+++ ../fptools/libraries/base/Data/List.hs	Wed Aug 25 20:22:13 2004
@@ -209,7 +209,7 @@
 import GHC.Base
 #endif
 
-infix 5 \\ 
+infix 5 \\ -- comment to fool cpp
 
 -- -----------------------------------------------------------------------------
 -- List functions
