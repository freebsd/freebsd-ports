--- Setup.hs.orig	2009-07-16 09:03:11.000000000 +0000
+++ Setup.hs	2009-07-16 09:03:29.000000000 +0000
@@ -3,4 +3,4 @@
 import Distribution.Simple
 
 main :: IO ()
-main = defaultMainWithHooks defaultUserHooks
+main = defaultMainWithHooks autoconfUserHooks
