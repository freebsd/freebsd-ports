--- modules/javafx.graphics/src/main/java/com/sun/glass/utils/NativeLibLoader.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/java/com/sun/glass/utils/NativeLibLoader.java
@@ -358,7 +358,7 @@ public class NativeLibLoader {
                     relativeDir = "../bin";
                 } else if (osName.startsWith("Mac")) {
                     relativeDir = ".";
-                } else if (osName.startsWith("Linux")) {
+                } else if (osName.startsWith("Linux") || osName.startsWith("FreeBSD")) {
                     relativeDir = ".";
                 }
 
@@ -374,7 +374,7 @@ public class NativeLibLoader {
                 } else if (osName.startsWith("Mac")) {
                     libPrefix = "lib";
                     libSuffix = ".dylib";
-                } else if (osName.startsWith("Linux")) {
+                } else if (osName.startsWith("Linux") || osName.startsWith("FreeBSD")) {
                     libPrefix = "lib";
                     libSuffix = ".so";
                 }
