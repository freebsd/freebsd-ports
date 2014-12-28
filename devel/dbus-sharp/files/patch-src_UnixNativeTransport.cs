
$FreeBSD$

--- src/UnixNativeTransport.cs.orig
+++ src/UnixNativeTransport.cs
@@ -93,10 +93,15 @@
 
 			byte[] sa = new byte[2 + p.Length + 1];
 
+#if false
 			//we use BitConverter to stay endian-safe
 			byte[] afData = BitConverter.GetBytes (UnixSocket.AF_UNIX);
 			sa[0] = afData[0];
 			sa[1] = afData[1];
+#endif
+
+			sa[0] = (byte) sa.Length;
+			sa[1] = 1; /* AF_UNIX */
 
 			for (int i = 0 ; i != p.Length ; i++)
 				sa[2 + i] = p[i];
@@ -111,10 +116,15 @@
 
 			byte[] sa = new byte[2 + 1 + p.Length];
 
+#if false
 			//we use BitConverter to stay endian-safe
 			byte[] afData = BitConverter.GetBytes (UnixSocket.AF_UNIX);
 			sa[0] = afData[0];
 			sa[1] = afData[1];
+#endif
+
+			sa[0] = (byte) sa.Length;
+			sa[1] = 1; /* AF_UNIX */
 
 			sa[2] = 0; //null prefix for abstract domain socket addresses, see unix(7)
 			for (int i = 0 ; i != p.Length ; i++)
