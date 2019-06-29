--- Ghidra/Framework/Utility/src/main/java/ghidra/framework/OperatingSystem.java.orig	2019-04-03 17:38:23 UTC
+++ Ghidra/Framework/Utility/src/main/java/ghidra/framework/OperatingSystem.java
@@ -20,6 +20,7 @@ public enum OperatingSystem {
 	WINDOWS("Windows"),
 	LINUX("Linux"),
 	MAC_OS_X("Mac OS X"),
+	FREEBSD("FreeBSD"),
 	UNSUPPORTED("Unsupported Operating System");
 
 	/**
