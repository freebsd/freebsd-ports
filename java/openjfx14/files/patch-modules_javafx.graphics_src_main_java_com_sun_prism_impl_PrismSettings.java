--- modules/javafx.graphics/src/main/java/com/sun/prism/impl/PrismSettings.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/java/com/sun/prism/impl/PrismSettings.java
@@ -221,6 +221,8 @@ public final class PrismSettings {
                     tryOrderArr = new String[] { "es2" };
             } else if (PlatformUtil.isLinux()) {
                 tryOrderArr = new String[] { "es2", "sw" };
+            } else if (PlatformUtil.isFreeBSD()) {
+                tryOrderArr = new String[] { "es2", "sw" };
             } else {
                 tryOrderArr = new String[] { "sw" };
             }
@@ -234,7 +236,7 @@ public final class PrismSettings {
             for (String s : split(rOrder.toLowerCase(), ",")) {
                 switch (s) {
                     case "pisces":
-                        rSpec = PlatformUtil.isEmbedded() || !PlatformUtil.isLinux()
+                        rSpec = PlatformUtil.isEmbedded() || !PlatformUtil.isLinux() || !PlatformUtil.isFreeBSD()
                                 ? RasterizerType.NativePisces
                                 : RasterizerType.JavaPisces;
                         break;
@@ -269,7 +271,7 @@ public final class PrismSettings {
                 boolean doNativePisces;
                 String npprop = systemProperties.getProperty("prism.nativepisces");
                 if (npprop == null) {
-                    doNativePisces = PlatformUtil.isEmbedded() || !PlatformUtil.isLinux();
+                    doNativePisces = PlatformUtil.isEmbedded() || !PlatformUtil.isLinux() || !PlatformUtil.isFreeBSD();
                 } else {
                     doNativePisces = Boolean.parseBoolean(npprop);
                 }
