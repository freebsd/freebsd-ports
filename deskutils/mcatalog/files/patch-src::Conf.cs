--- src/Conf.cs.orig	Mon Oct 25 00:05:00 2004
+++ src/Conf.cs	Mon Oct 25 00:05:04 2004
@@ -30,25 +30,20 @@
 
 	public static string HomeDir {
 		get {
-			StringBuilder sbHome = new StringBuilder (home);
-			if (!Directory.Exists(sbHome.ToString())) {
-				Directory.CreateDirectory (sbHome.ToString());
+			if (!Directory.Exists(home)) {
+				Directory.CreateDirectory (home);
 			}
-			StringBuilder sbCache = sbHome.Append ("/cache");
-			if (!Directory.Exists(sbCache.ToString())) {
-				Directory.CreateDirectory (sbCache.ToString());
+			if (!Directory.Exists(home+"/cache")) {
+				Directory.CreateDirectory (home+"/cache");
 			}
-			StringBuilder sbSmall = sbCache.Append ("/small");
-			if (!Directory.Exists(sbSmall.ToString())) {
-				Directory.CreateDirectory (sbSmall.ToString());
+			if (!Directory.Exists(home+"/cache/small")) {
+				Directory.CreateDirectory (home+"/cache/small");
 			}
-			StringBuilder sbMedium = sbCache.Append ("/medium");
-			if (!Directory.Exists(sbMedium.ToString())) {
-				Directory.CreateDirectory (sbMedium.ToString());
+			if (!Directory.Exists(home+"/cache/medium")) {
+				Directory.CreateDirectory (home+"/cache/medium");
 			}
-			StringBuilder sbLarge = sbCache.Append ("/large");
-			if (!Directory.Exists(sbLarge.ToString())) {
-				Directory.CreateDirectory (sbLarge.ToString());
+			if (!Directory.Exists(home+"/cache/large")) {
+				Directory.CreateDirectory (home+"/cache/large");
 			}
 			return home;
 		}
