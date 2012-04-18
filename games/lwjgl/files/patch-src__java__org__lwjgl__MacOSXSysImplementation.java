Obtained from http://foo.poildetroll.net/minecraft/lwjgl-2.7.1-freebsd.diff


--- ./src/java/org/lwjgl/MacOSXSysImplementation.java.orig	2011-02-06 19:23:32.000000000 +0000
+++ ./src/java/org/lwjgl/MacOSXSysImplementation.java	2012-03-26 18:14:03.135376460 +0000
@@ -33,7 +33,7 @@
 
 import java.awt.Toolkit;
 
-import com.apple.eio.FileManager;
+// import com.apple.eio.FileManager;
 
 /**
  *
@@ -55,7 +55,7 @@
 
 	public boolean openURL(String url) {
 		try {
-			FileManager.openURL(url);
+			// FileManager.openURL(url);
 			return true;
 		} catch (Exception e) {
 			LWJGLUtil.log("Exception occurred while trying to invoke browser: " + e);
