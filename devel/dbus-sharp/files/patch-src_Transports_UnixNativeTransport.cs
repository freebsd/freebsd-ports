--- src/Transports/UnixNativeTransport.cs.orig	2014-06-24 17:10:54 UTC
+++ src/Transports/UnixNativeTransport.cs
@@ -94,10 +94,8 @@ namespace DBus.Transports
 
 			byte[] sa = new byte[2 + p.Length + 1];
 
-			//we use BitConverter to stay endian-safe
-			byte[] afData = BitConverter.GetBytes (UnixSocket.AF_UNIX);
-			sa[0] = afData[0];
-			sa[1] = afData[1];
+			sa[0] = (byte) sa.Length;
+			sa[1] = 1; /* AF_UNIX */
 
 			for (int i = 0 ; i != p.Length ; i++)
 				sa[2 + i] = p[i];
@@ -112,10 +110,8 @@ namespace DBus.Transports
 
 			byte[] sa = new byte[2 + 1 + p.Length];
 
-			//we use BitConverter to stay endian-safe
-			byte[] afData = BitConverter.GetBytes (UnixSocket.AF_UNIX);
-			sa[0] = afData[0];
-			sa[1] = afData[1];
+			sa[0] = (byte) sa.Length;
+			sa[1] = 1; /* AF_UNIX */
 
 			sa[2] = 0; //null prefix for abstract domain socket addresses, see unix(7)
 			for (int i = 0 ; i != p.Length ; i++)
