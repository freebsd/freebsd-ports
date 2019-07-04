--- Database/Keys/SQL.hs.orig	2019-06-26 16:31:40 UTC
+++ Database/Keys/SQL.hs
@@ -9,6 +9,7 @@
 {-# LANGUAGE OverloadedStrings, GADTs, FlexibleContexts #-}
 {-# LANGUAGE MultiParamTypeClasses, GeneralizedNewtypeDeriving #-}
 {-# LANGUAGE RankNTypes, ScopedTypeVariables #-}
+{-# LANGUAGE UndecidableInstances #-}
 
 module Database.Keys.SQL where
 
