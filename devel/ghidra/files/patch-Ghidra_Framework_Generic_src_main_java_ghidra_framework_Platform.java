--- Ghidra/Framework/Generic/src/main/java/ghidra/framework/Platform.java.orig	2019-04-03 17:38:23 UTC
+++ Ghidra/Framework/Generic/src/main/java/ghidra/framework/Platform.java
@@ -70,7 +70,17 @@ public enum Platform {
 	 */
 	MAC_UNKNOWN(OperatingSystem.MAC_OS_X, Architecture.UNKNOWN, "osx64", ".dylib", ""),
 
+ 	/**
+	 * Identifies a FreeBSD OS.
+	 */
+	FREEBSD_32(OperatingSystem.FREEBSD, Architecture.X86, "freebsd32", ".so", ""),
+
 	/**
+	 * Identifies a FreeBSD OS.
+	 */
+	FREEBSD_64(OperatingSystem.FREEBSD, Architecture.X86_64, "freebsd64", ".so", ""),
+
+	/**
 	 * Identifies an unsupported OS.
 	 */
 	UNSUPPORTED(OperatingSystem.UNSUPPORTED, Architecture.UNKNOWN, null, null, "");
@@ -144,6 +154,15 @@ public enum Platform {
 			paths.add("/usr/lib");
 			paths.add("/usr/X11R6/bin");
 			paths.add("/usr/X11R6/lib");
+		}
+		else if (operatingSystem == OperatingSystem.FREEBSD) {
+			paths.add("/bin");
+			paths.add("/lib");
+			paths.add("/usr/bin");
+			paths.add("/usr/lib");
+			paths.add("/usr/local/bin");
+			paths.add("/usr/local/lib");
+			paths.add("/usr/local/lib/compat");
 		}
 		else if (CURRENT_PLATFORM == WIN_64) {
 			String windir = System.getenv("SystemRoot");
