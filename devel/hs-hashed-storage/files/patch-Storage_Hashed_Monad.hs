--- Storage/Hashed/Monad.hs.orig	2014-04-07 13:32:06 UTC
+++ Storage/Hashed/Monad.hs
@@ -1,4 +1,4 @@
-{-# LANGUAGE ScopedTypeVariables, BangPatterns, TypeSynonymInstances, UndecidableInstances, FlexibleInstances #-}
+{-# LANGUAGE ScopedTypeVariables, BangPatterns, TypeSynonymInstances, UndecidableInstances, FlexibleInstances, FlexibleContexts #-}
 
 -- | An experimental monadic interface to Tree mutation. The main idea is to
 -- simulate IO-ish manipulation of real filesystem (that's the state part of
