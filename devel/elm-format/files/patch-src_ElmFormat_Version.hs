--- src/ElmFormat/Version.hs.orig	2019-07-15 11:58:38 UTC
+++ src/ElmFormat/Version.hs
@@ -1,11 +1,9 @@
 module ElmFormat.Version (asString, experimental) where
 
-import qualified Build_elm_format
 
-
 asString :: String
 asString =
-    Build_elm_format.gitDescribe
+    "%%PORTVERSION%%"
 
 
 experimental :: Maybe String
