--- Database/Fsck.hs.orig	2019-06-26 16:31:40 UTC
+++ Database/Fsck.hs
@@ -9,6 +9,7 @@
 {-# LANGUAGE OverloadedStrings, GADTs, FlexibleContexts #-}
 {-# LANGUAGE MultiParamTypeClasses, GeneralizedNewtypeDeriving #-}
 {-# LANGUAGE RankNTypes #-}
+{-# LANGUAGE UndecidableInstances #-}
 
 module Database.Fsck (
 	FsckHandle,
