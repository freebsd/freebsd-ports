--- src/bareFTP.Protocol.Ftp/ftp/ListParser.cs.bak	2015-01-29 07:46:28.278935333 -0800
+++ src/bareFTP.Protocol.Ftp/ftp/ListParser.cs	2015-01-29 07:47:03.217939461 -0800
@@ -22,7 +22,9 @@
 
 using System;
 using System.Collections.Generic;
-using System.Text;z
+using System.Text;
+using System.Globalization;
+
 namespace bareFTP.Protocol.Ftp
 {
 	public class ListParser
