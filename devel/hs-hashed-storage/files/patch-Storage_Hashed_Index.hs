--- Storage/Hashed/Index.hs.orig	2014-04-07 13:32:06 UTC
+++ Storage/Hashed/Index.hs
@@ -1,4 +1,4 @@
-{-# LANGUAGE CPP, ScopedTypeVariables, MultiParamTypeClasses #-}
+{-# LANGUAGE CPP, ScopedTypeVariables, MultiParamTypeClasses, FlexibleContexts #-}
 
 -- | This module contains plain tree indexing code. The index itself is a
 -- CACHE: you should only ever use it as an optimisation and never as a primary
