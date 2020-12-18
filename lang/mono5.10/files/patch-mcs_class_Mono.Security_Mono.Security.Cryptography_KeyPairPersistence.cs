--- mcs/class/Mono.Security/Mono.Security.Cryptography/KeyPairPersistence.cs.orig	2017-07-20 18:10:59 UTC
+++ mcs/class/Mono.Security/Mono.Security.Cryptography/KeyPairPersistence.cs
@@ -244,7 +244,7 @@ namespace Mono.Security.Cryptography {
 					if ((_machinePath == null) || (!_machinePathExists)) {
 						_machinePath = Path.Combine (
 							Environment.GetFolderPath (Environment.SpecialFolder.CommonApplicationData),
-							".mono");
+							"mono");
 						_machinePath = Path.Combine (_machinePath, "keypairs");
 
 						_machinePathExists = Directory.Exists (_machinePath);
