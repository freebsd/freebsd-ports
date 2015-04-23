--- src/games/stendhal/server/core/engine/GenerateINI.java.orig	2015-01-08 08:02:23 UTC
+++ src/games/stendhal/server/core/engine/GenerateINI.java
@@ -29,7 +29,10 @@ import marauroa.common.crypto.RSAKey;
  * @author hendrik
  */
 public class GenerateINI {
-
+	
+	/** Server configuration directory */
+	private static String serverConfigDir = System.getenv("HOME") + "/.config/stendhal";
+	
 	/** The name of the output file. */
 	private static String filename = "server.ini";
 
@@ -218,7 +221,7 @@ public class GenerateINI {
 	}
 
 	private static String getStatisticsFilename() {
-		return "./server_stats.xml";
+		return serverConfigDir + "/server_stats.xml";
 	}
 
 	private static String getTurnLength() {
