--- ./src/FRP/Reactive/Internal/Chan.hs.orig	2010-07-28 18:48:55.000000000 +0200
+++ ./src/FRP/Reactive/Internal/Chan.hs	2012-05-12 22:41:22.000000000 +0200
@@ -1,4 +1,4 @@
-{-# LANGUAGE CPP #-}
+{-# LANGUAGE CPP, StandaloneDeriving, DeriveDataTypeable #-}
 {-# OPTIONS_GHC -Wall #-}
 -----------------------------------------------------------------------------
 -- |
