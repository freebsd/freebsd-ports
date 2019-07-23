--- modules/graphics/src/main/java/com/sun/prism/impl/PrismSettings.java.orig	2018-12-10 16:30:22 UTC
+++ modules/graphics/src/main/java/com/sun/prism/impl/PrismSettings.java
@@ -212,6 +212,8 @@ public final class PrismSettings {
                     tryOrderArr = new String[] { "es2" };
             } else if (PlatformUtil.isLinux()) {
                 tryOrderArr = new String[] { "es2", "sw" };
+            } else if (PlatformUtil.isFreeBSD()) {
+                tryOrderArr = new String[] { "es2", "sw" };
             } else {
                 tryOrderArr = new String[] { "sw" };
             }
@@ -221,7 +223,7 @@ public final class PrismSettings {
 
         String npprop = systemProperties.getProperty("prism.nativepisces");
         if (npprop == null) {
-            doNativePisces = PlatformUtil.isEmbedded() || !PlatformUtil.isLinux();
+            doNativePisces = PlatformUtil.isEmbedded() || !PlatformUtil.isLinux() || !PlatformUtil.isFreeBSD();
         } else {
             doNativePisces = Boolean.parseBoolean(npprop);
         }
