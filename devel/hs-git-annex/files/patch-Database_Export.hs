--- Database/Export.hs.orig	2019-06-26 16:31:40 UTC
+++ Database/Export.hs
@@ -10,6 +10,7 @@
 {-# LANGUAGE MultiParamTypeClasses, GeneralizedNewtypeDeriving #-}
 {-# LANGUAGE RankNTypes #-}
 {-# LANGUAGE CPP #-}
+{-# LANGUAGE UndecidableInstances #-}
 
 module Database.Export (
 	ExportHandle,
