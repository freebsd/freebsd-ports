--- mcs/class/Mono.Security/Mono.Security.X509/X509StoreManager.cs.orig	2017-07-20 18:10:59 UTC
+++ mcs/class/Mono.Security/Mono.Security.X509/X509StoreManager.cs
@@ -73,7 +73,7 @@ namespace Mono.Security.X509 {
 				if (_localMachinePath == null) {
 					_localMachinePath = Path.Combine (
 						Environment.GetFolderPath (Environment.SpecialFolder.CommonApplicationData),
-						".mono");
+						"mono");
 					_localMachinePath = Path.Combine (_localMachinePath, "certs");
 				}
 				return _localMachinePath;
@@ -97,7 +97,7 @@ namespace Mono.Security.X509 {
 				if (_newLocalMachinePath == null) {
 					_newLocalMachinePath = Path.Combine (
 						Environment.GetFolderPath (Environment.SpecialFolder.CommonApplicationData),
-						".mono");
+						"mono");
 					_newLocalMachinePath = Path.Combine (_newLocalMachinePath, "new-certs");
 				}
 				return _newLocalMachinePath;
