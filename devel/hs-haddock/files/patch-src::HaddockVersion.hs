--- haddock/src/HaddockVersion.hs.orig	Tue Feb  1 22:39:03 2005
+++ haddock/src/HaddockVersion.hs	Tue Feb  1 22:39:27 2005
@@ -14,5 +14,4 @@
 
 -- The version comes in via CPP from mk/version.mk
 projectVersion :: String
-projectVersion = tail "\ 
-  \ HADDOCK_VERSION"
+projectVersion = tail "HADDOCK_VERSION"
