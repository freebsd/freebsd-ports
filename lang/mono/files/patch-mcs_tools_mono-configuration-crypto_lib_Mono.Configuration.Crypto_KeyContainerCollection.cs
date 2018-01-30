--- mcs/tools/mono-configuration-crypto/lib/Mono.Configuration.Crypto/KeyContainerCollection.cs.orig	2017-07-20 18:10:59 UTC
+++ mcs/tools/mono-configuration-crypto/lib/Mono.Configuration.Crypto/KeyContainerCollection.cs
@@ -32,7 +32,7 @@ namespace Mono.Configuration.Crypto
 			string topPath;
 
 			if (machineStore)
-				topPath = Path.Combine (Environment.GetFolderPath (Environment.SpecialFolder.CommonApplicationData), ".mono");
+				topPath = Path.Combine (Environment.GetFolderPath (Environment.SpecialFolder.CommonApplicationData), "mono");
 			else
 				topPath = Path.Combine (Environment.GetFolderPath (Environment.SpecialFolder.ApplicationData), ".mono");
 			topPath = Path.Combine (topPath, "keypairs");
