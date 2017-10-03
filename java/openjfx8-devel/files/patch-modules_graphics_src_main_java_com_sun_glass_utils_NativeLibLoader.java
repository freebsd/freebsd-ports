--- modules/graphics/src/main/java/com/sun/glass/utils/NativeLibLoader.java.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/java/com/sun/glass/utils/NativeLibLoader.java
@@ -173,7 +173,7 @@ public class NativeLibLoader {
                     relativeDir = "../../bin";
                 } else if (osName.startsWith("Mac")) {
                     relativeDir = "..";
-                } else if (osName.startsWith("Linux")) {
+                } else if (osName.startsWith("Linux") || osName.startsWith("FreeBSD")) {
                     relativeDir = "../" + System.getProperty("os.arch");
                 }
 
@@ -189,7 +189,7 @@ public class NativeLibLoader {
                 } else if (osName.startsWith("Mac")) {
                     libPrefix = "lib";
                     libSuffix = ".dylib";
-                } else if (osName.startsWith("Linux")) {
+                } else if (osName.startsWith("Linux") || osName.startsWith("FreeBSD")) {
                     libPrefix = "lib";
                     libSuffix = ".so";
                 }
