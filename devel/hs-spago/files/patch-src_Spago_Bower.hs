--- src/Spago/Bower.hs.orig	2022-05-03 16:26:05 UTC
+++ src/Spago/Bower.hs
@@ -9,7 +9,7 @@ import qualified Data.Aeson.Encode.Pretty   as Pretty
 
 import qualified Data.Aeson                 as Aeson
 import qualified Data.Aeson.Encode.Pretty   as Pretty
-import qualified Data.HashMap.Strict        as HashMap
+import qualified Data.Aeson.KeyMap          as KeyMap
 import qualified Data.Text                  as Text
 import qualified System.Info
 import qualified Turtle
@@ -109,7 +109,7 @@ mkBowerVersion packageName version (Repo repo) = do
       Just (Object obj) -> pure obj
       _ -> die [ display $ "Unable to decode output from `bower " <> Text.intercalate " " args <> "`: ", display out ]
 
-    if HashMap.member "version" info
+    if KeyMap.member "version" info
       then pure $ Bower.VersionRange $ "^" <> version
       else pure $ Bower.VersionRange $ repo <> "#" <> version
 
